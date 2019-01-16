#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Search_Maximum(vector<int> list) {
	int max = 0, N = list.size();
	for (int i = 0; i < list.size(); i++) {
		int point = list[i] + N;
		if (max < point) max = point;
		N--;
	}
	return max;
}

int Search_Person(vector<int> list) {
	int cnt = 0, N = list.size();
	int max = Search_Maximum(list);
	for (int i = 0; i < N; i++) {
		if (list[i] + N >= max) cnt++;
	}
	return cnt;
}

int main() {
	int testcase;
	cin >> testcase;
	for (int T = 1; T <= testcase; T++) {
		int N;
		cin >> N;
		vector<int> list;
		list.reserve(N);
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			list.push_back(input);
		}
		sort(list.begin(), list.end());
		cout << "Case #" << T << '\n' << Search_Person(list) << '\n';
	}
	return 0;
}