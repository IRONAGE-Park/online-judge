#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 1; i <= testcase; i++) {
		int N, K;
		cin >> N >> K;
		vector<int> list;
		list.reserve(N);
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			list.push_back(input);
		}
		sort(list.begin(), list.end(), compare);
		int sum = 0;
		for (int i = 0; i < K; i++) sum += list[i];
		cout << "Case #" << i << '\n' << sum << '\n';
	}
	return 0;
}