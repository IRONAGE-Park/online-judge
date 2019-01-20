#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>

using namespace std;

void split(string record, string *state, string *id, string *nickname) { // 입력 라인을 상태와 id, 닉네임으로 구분시켜주는 함수.
	string w;
	vector<string> word;
	for (stringstream sts(record); (sts >> w);) {  /// 문자열 s로 만들어진 문자열 스트림 sts생성
												   /// 문자열 스트림 sts를 이용하여 한 단어씩 w에 입력
												   /// sts에 남은 단어가 없다면 NULL 반환
		word.push_back(w);               /// 단어 w를 word에 추가
	}
	*state = word[0]; *id = word[1];
	if (word.size() == 3) {
		*nickname = word[2];
	}
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	string state, id, nickname;
	map<string, string> DB;
	for (int i = 0; i < record.size(); i++) {
		split(record[i], &state, &id, &nickname);
		if (state[0] == 'E') { // 입력 상태로 "Enter"가 들어왔을 경우
			if (DB.find(id) == DB.end()) { // 처음 입력된 id인 경우
				DB.insert(make_pair(id, nickname));
			}
			else { // 한 번 나갔다가 들어온 id의 경우
				DB.erase(id);
				DB.insert(make_pair(id, nickname));
			}
		}
		else if (state[0] == 'C') { // 입력 상태로 "Change"가 들어왔을 경우
			DB.erase(id);
			DB.insert(make_pair(id, nickname));
		}
	}
	/* 최종적인 닉네임 정보 갱신 */
	for (int i = 0; i < record.size(); i++) {
		if (record[i][0] == 'C') continue;
		else {
			string line;
			split(record[i], &state, &id, &nickname);
			if (state[0] == 'E') { // 입력 상태가 "Enter"
				line = DB.find(id)->second + "님이 들어왔습니다.";
				answer.push_back(line);
			}
			else { // 입력 상태가 "Leave"
				line = DB.find(id)->second + "님이 나갔습니다.";
				answer.push_back(line);
			}
		}
	}
	return answer;
}

int main() {
	int N;
	cin >> N;
	getchar();
	vector<string> input(N);
	for (int i = 0; i < N; i++) {
		getline(cin, input[i]);
	}
	vector<string> sol = solution(input);
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << '\n';
	}
	return 0;
}