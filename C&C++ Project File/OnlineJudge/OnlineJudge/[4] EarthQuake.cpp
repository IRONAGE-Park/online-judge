#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct { int size, pat; }EQ; // 그 크기와 패턴

bool compare(EQ a, EQ b) {
	if (a.size == b.size) return a.pat < b.pat;
	else return a.size < b.size;
}

bool Likelihood(vector<EQ> data, int K) { // 지진이 일어날 가능성을 확인하는 함수
	sort(data.begin(), data.end(), compare); // size에 따라 오름차순으로 정렬
	vector<int> table;
	table.push_back(0);
	for (int i = 0; i < data.size(); i++) {
		int idx = lower_bound(table.begin(), table.end(), data[i].pat) - table.begin();
		if (idx == table.size()) table.push_back(data[i].pat);
		else table[idx] = data[i].pat;
	}
	if (data.size() - table.size() + 1 <= K) return true;
	else return false;
}

int Solution(vector<int> data, vector<int> pattern, int K) {
	int Answer = 0;
	for (int i = 0; i <= data.size() - pattern.size(); i++) {
		vector<EQ> comp;
		comp.reserve(pattern.size());
		for (int j = 0; j < pattern.size(); j++) {
			EQ eq = { data[i + j], pattern[j] };
			comp.push_back(eq);
		} // 구조체 EQ형태로 두 리스트를 조합
		if (Likelihood(comp, K)) Answer++;
		comp.clear();
	}
	return Answer;
}

int main() {
	int testcase;
	cin >> testcase;
	for (int T = 1; T <= testcase; T++) {
		int N, M, K; // N = 측정한 지진파 데이터 길이, M = 패턴의 길이, K = 허용가능 삭제 수
		cin >> N >> M >> K;
		vector<int> data, pattern; // 측정한 지진파 데이터와 패턴
		data.resize(N); pattern.resize(M);
		for (int i = 0; i < N; i++) cin >> data[i];
		for (int i = 0; i < M; i++) cin >> pattern[i];
		/* INPUT DATA */
		cout << "Case #" << T << '\n' << Solution(data, pattern, K) << '\n';
	}
	return 0;
}