#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>

using namespace std;

void split(string record, string *state, string *id, string *nickname) { // �Է� ������ ���¿� id, �г������� ���н����ִ� �Լ�.
	string w;
	vector<string> word;
	for (stringstream sts(record); (sts >> w);) {  /// ���ڿ� s�� ������� ���ڿ� ��Ʈ�� sts����
												   /// ���ڿ� ��Ʈ�� sts�� �̿��Ͽ� �� �ܾ w�� �Է�
												   /// sts�� ���� �ܾ ���ٸ� NULL ��ȯ
		word.push_back(w);               /// �ܾ� w�� word�� �߰�
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
		if (state[0] == 'E') { // �Է� ���·� "Enter"�� ������ ���
			if (DB.find(id) == DB.end()) { // ó�� �Էµ� id�� ���
				DB.insert(make_pair(id, nickname));
			}
			else { // �� �� �����ٰ� ���� id�� ���
				DB.erase(id);
				DB.insert(make_pair(id, nickname));
			}
		}
		else if (state[0] == 'C') { // �Է� ���·� "Change"�� ������ ���
			DB.erase(id);
			DB.insert(make_pair(id, nickname));
		}
	}
	/* �������� �г��� ���� ���� */
	for (int i = 0; i < record.size(); i++) {
		if (record[i][0] == 'C') continue;
		else {
			string line;
			split(record[i], &state, &id, &nickname);
			if (state[0] == 'E') { // �Է� ���°� "Enter"
				line = DB.find(id)->second + "���� ���Խ��ϴ�.";
				answer.push_back(line);
			}
			else { // �Է� ���°� "Leave"
				line = DB.find(id)->second + "���� �������ϴ�.";
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