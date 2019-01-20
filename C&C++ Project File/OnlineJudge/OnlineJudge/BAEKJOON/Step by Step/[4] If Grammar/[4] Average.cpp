#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename Iter>
float Sol(Iter begin, Iter end) {
	float maximum = 0, sum = 0;
	for (; begin != end; begin++) {
		maximum = maximum > *begin ? maximum : *begin;
		sum += *begin;
	}
	return sum / maximum * 100;
}

int main() {
	int n;
	cin >> n;
	vector<float> v;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		float num;
		cin >> num;
		v.push_back(num);
	}
	float avg = Sol(v.begin(), v.end());
	cout << avg / n << endl;
	return 0;
}