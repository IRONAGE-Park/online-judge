#include<iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int A, B;
		cin >> A >> B;
		cout << A + B << '\n';
	}
	return 0;
}