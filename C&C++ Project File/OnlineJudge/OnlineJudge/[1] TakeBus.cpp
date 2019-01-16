#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int Solution(vector<int> list, int K) {
	priority_queue<int> queue;
	queue.push(list.at(0));
	for (int i = 1; i < list.size(); i++) {
		if (queue.top() - list.at(i) > K) queue.pop();
		queue.push(list.at(i));
	}
	return queue.size();
}

int main() {
	int testcase;
	cin >> testcase;
	for (int T = 1; T <= testcase; T++) {
		int N, K; // N = 선수의 인원 수, K = 실력 범위
		cin >> N >> K;
		/* INPUT DATA */
		vector<int> list;
		list.reserve(N);
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			list.push_back(input);
		}
		sort(list.begin(), list.end(), compare); // 오름차순으로 정렬
		cout << "Case #" << T << '\n' << Solution(list, K) << '\n';
		list.clear();
	}
	return 0;
}