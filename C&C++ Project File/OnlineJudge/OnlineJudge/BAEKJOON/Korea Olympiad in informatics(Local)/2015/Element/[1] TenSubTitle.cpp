#include<iostream>

using namespace std;

int main() {
	int num, c_num, result = 0;
	cin >> num;

	for (int i = 0; i < 5; i++) {
		cin >> c_num;
		if (c_num == num) result++;
	}
	cout << result << endl;
	return 0;
}