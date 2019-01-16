#include<iostream>

using namespace std;

int main() {
	double n1, n2;
	cin >> n1 >> n2;

	double num = n1 / n2;

	cout.setf(ios::fixed);
	cout.precision(9);
	cout << num << endl;

	return 0;
}