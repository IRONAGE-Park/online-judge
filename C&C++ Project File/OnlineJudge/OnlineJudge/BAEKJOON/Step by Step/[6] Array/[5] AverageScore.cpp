#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define NUM 5

using namespace std;

template<typename Iter>
void Sol(Iter begin, Iter end) {
	int sum = 0;
	while (begin != end) {
		if (*begin > 40) {
			sum += *begin;
		}
		else {
			sum += 40;
		}
		begin++;
	}
	cout << sum / NUM << endl;
}

int main() {
	vector<int> v(NUM);
	v.reserve(NUM);
	for (int i = 0; i < NUM; i++) {
		cin >> v.at(i);
	}
	Sol(v.begin(), v.end());
	return 0;
}