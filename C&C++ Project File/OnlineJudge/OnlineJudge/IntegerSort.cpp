#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Sum(vector<int> list) {
	int sum = 0;
	for (int i = 0; i < list.size(); i++) {
		if(i % 2 == 0) sum += list[i];
		else sum -= list[i];
	}
	return sum;
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
		cout << "Case #" << T << '\n' << Sum(list) << '\n';
	}
	return 0;
}