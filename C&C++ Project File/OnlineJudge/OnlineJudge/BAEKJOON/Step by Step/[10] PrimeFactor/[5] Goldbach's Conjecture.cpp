#include<iostream>
#include<vector>
#include<cmath>
#define MAX 10000

using namespace std;

bool PrimeFactor(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

vector<int> list;
vector<bool> check;

void CreatePrimeNumberList() { // 수 10000까지 소수의 리스트를 생성.
	check.resize(MAX + 1, false);
	for (int i = 2; i <= MAX; i++) {
		if (PrimeFactor(i)) {
			list.push_back(i);
			check[i] = true;
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;
	CreatePrimeNumberList();
	while (testcase--) {
		int N;
		int Gp1, Gp2;
		cin >> N;
		for (int i = 0; i < list.size() && list[i] <= N / 2; i++) {
			if (check[list[i]] && check[N - list[i]]) {
				Gp1 = list[i], Gp2 = N - list[i];
			}
		}
		cout << Gp1 << ' ' << Gp2 << '\n';
	}
	return 0;
}