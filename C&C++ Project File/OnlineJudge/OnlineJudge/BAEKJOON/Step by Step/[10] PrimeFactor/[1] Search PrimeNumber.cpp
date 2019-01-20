#include<iostream>
#include<cmath>
using namespace std;

bool PrimeFactor(int n) {
	if (n == 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int N, cnt = 0;
	cin >> N;
	while (N--) {
		int num;
		cin >> num;
		if (PrimeFactor(num)) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
