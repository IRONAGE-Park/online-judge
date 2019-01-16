#include<iostream>

using namespace std;

int Solution(int distance) {
	int range, cnt = 0;
	for (range = 1; range * 2 < distance; range++) {
		cnt += 2;
		distance -= range * 2;
	}
	if (distance > 0) {
		if (distance > range)
			cnt += 2;
		else
			cnt += 1;
	}
	return cnt;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int x, y;
		cin >> x >> y;
		cout << Solution(y - x) << '\n';
	}
	return 0;
}