#include<iostream>
#include<vector>

using namespace std;

template<typename Iter>
double Sol(Iter begin, Iter end, int n) {
	double avg, sum = 0, cnt = 0, ans;
	Iter init = begin;
	for (; begin != end; begin++) {
		sum += *begin;
	}
	avg = sum / n;
	for (begin = init; begin != end; begin++) {
		if (*begin > avg) {
			cnt++;
		}
	}
	ans = (cnt / n) * 100;
	// ans = (ans + 0.0004);
	return ans;
}

int main() {
	int testcase;
	cin >> testcase;
	cout.setf(ios::fixed);

	vector<double> v;

	while (testcase--) {
		int n;
		cin >> n;
		v.reserve(n);
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		cout.precision(3);
		cout << Sol(v.begin(), v.end(), n) << "%" << endl;
		v.clear();
	}
	return 0;
}