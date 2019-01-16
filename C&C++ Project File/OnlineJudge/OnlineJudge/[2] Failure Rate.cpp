#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Fail {
	double percent;
	int stage;
}Fail;

bool compare(Fail a, Fail b) {
	if (a.percent == b.percent) {
		return a.stage < b.stage;
	}
	return a.percent > b.percent;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer(N);
	vector<Fail> fail(N);
	vector<int> clear(N + 1);
	for (int i = 0; i < stages.size(); i++) clear[stages[i] - 1]++;
	int clearNum = clear[N];
	for (int i = clear.size() - 2; i >= 0; i--) {
		if (clearNum == 0 && clear[i] == 0) fail[i].percent = 0.0;
		else fail[i].percent = (double)clear[i] / (double)clearNum;
		fail[i].stage = i + 1;
		clearNum += clear[i];
	}
	sort(fail.begin(), fail.end(), compare);
	for (int i = 0; i < fail.size(); i++) answer[i] = fail[i].stage;
	return answer;
}

int main() {
	int N;
	cin >> N;
	vector<int> stages;
	int stage;
	while (cin >> stage) {
		if (!stage) break;
		stages.push_back(stage);
	}
	vector<int> sol = solution(N, stages);
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << ' ';
	}
	cout << '\n';
	return 0;
}