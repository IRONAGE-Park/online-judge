#include<iostream>

using namespace std;

int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	int num;
	num = (n1 + n2) % n3;
	cout << num << endl;
	num = ((n1 % n3) + (n2 % n3)) % n3;
	cout << num << endl;
	num = (n1 * n2) % n3;
	cout << num << endl;
	num = ((n1 % n3) * (n2 % n3)) % n3;
	cout << num << endl;

	return 0;
}