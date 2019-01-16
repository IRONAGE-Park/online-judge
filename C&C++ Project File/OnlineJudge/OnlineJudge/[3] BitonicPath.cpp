#include<iostream>
#include<vector>

using namespace std;

vector< vector<int> > graph; // 그래프
vector<int> toS; // S에서 부터
vector<int> toT; // T에서 부터



int main() {
	int testcase;
	cin >> testcase;
	for (int T = 1; T <= testcase; T++) {
		int N, M;
		cin >> N >> M;
		vector<int> edge(N);
		graph.resize(N, edge);
		for (int i = 0; i < M; i++) {
			int I, J, K;
			cin >> I >> J >> K;
			graph[I][J] = K;
			graph[J][I] = K;
		}
		/* 그래프 생성 */

		int Answer = 0;
		cout << "Case #" << T << '\n' << Answer << '\n';
	}
	return 0;
}