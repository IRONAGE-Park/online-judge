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

int Sum(vector<int> list) {
	int sum = 0;
	for (int i = 0; i < list.size(); i++) {
		sum += list[i];
	}
	return sum;
}

int main() {
	int M, N;
	cin >> M >> N;
	vector<int> list;
	for (; M <= N; M++) {
		if (PrimeFactor(M))
			list.push_back(M);
	}
	if (list.size()) cout << Sum(list) << '\n' << list[0];
	else cout << -1;
	return 0;
}
