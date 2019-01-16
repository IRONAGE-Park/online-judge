#include<http_client.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool checkUnique(vector< vector<string> > relation, vector<int> list) {
	for (int i = 0; i < relation.size(); i++) {
		for (int j = i + 1; j < list.size(); j++) {
			vector<string> compare = relation[i];

		}
	}
	return false;
}

int DFS(vector< vector<string> > relation, vector<int> list) {
	int answer = 0;
	for (int i = 0; i) {

	}
	return answer;
}

int solution(vector< vector<string> > relation) {
	vector<int> list(1);
	int answer = 0;
	for (int i = 0; i < relation[0].size(); i++) {
		list[0] = i;
		answer += DFS(relation, list);
	}
	return 0;
}

int main() {
	vector< vector<string> > relation;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<string> tuple(M);
		for (int j = 0; j < M; j++) {
			cin >> tuple[j];
		}
		relation.push_back(tuple);
		tuple.clear();
	}
	cout << solution(relation) << '\n';
	return 0;
}