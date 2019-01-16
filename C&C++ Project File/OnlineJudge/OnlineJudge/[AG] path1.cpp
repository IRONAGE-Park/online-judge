#include<iostream>
#include<fstream>

using namespace std;

typedef long long int lint;

lint Factorial(int n, int range) {
	if (n < 2 || n == range) return 1;
	else return n * Factorial(n - 1, range);
}

lint Solution(int N, int M, int K) {
	lint first, second;
	if (K != 0) {
		int disX = (K - 1) % M, disY = (K - 1) / M;
		if (disX < disY) {
			first = Factorial(disX + disY, disY) / Factorial(disX, 1);
			second = Factorial(M - (disX + 1) + N - (disY + 1), M - (disX + 1)) / Factorial(N - (disY + 1), 1);
		}
		else {
			first = Factorial(disX + disY, disX) / Factorial(disY, 1);
			second = Factorial(M - (disX + 1) + N - (disY + 1), N - (disY + 1)) / Factorial(M - (disX + 1), 1);
		}
	}
	else {
		second = 1;
		if (M < N) {
			first = Factorial(M + N - 2, N - 1) / Factorial(M - 1, 1);
		}
		else {
			first = Factorial(M + N - 2, M - 1) / Factorial(N - 1, 1);
		}
	}
	return first * second;
}

int main() {
	ifstream inp("path.inp");
	ofstream out("path.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int N, M, K;
		inp >> N >> M >> K;
		out << Solution(N, M, K) << '\n';
	}
	inp.close();
	out.close();
	return 0;
}