#include<iostream>
#include<vector>
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
	while (true) {
		int N;
		cin >> N;
		if (!N) break;
		int cnt = 0;
		for (int i = N + 1; i <= 2 * N; i++) {
			if (PrimeFactor(i))
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
