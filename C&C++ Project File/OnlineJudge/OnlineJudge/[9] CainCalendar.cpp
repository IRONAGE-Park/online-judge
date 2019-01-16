#include<iostream>

using namespace std;

int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int M, N, X, Y, years = 0;
		cin >> M >> N >> X >> Y;
		int limit = lcm(M, N), answer = -1;
		while (X <= limit) {
			if (X % N == Y % N) {
				answer = X;
				break;
			}
			X += M;
		}
		cout << answer << '\n';
	}
	return 0;
}