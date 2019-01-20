#include<iostream>
#include<string>

using namespace std;

int main() {
	string str, s1, s2;
	int firstNum, num, n1, n2, cnt = 0;
	cin >> firstNum;
	num = firstNum;

	if (num < 10) {
		str = "0" + to_string(num);
	}
	else str = to_string(num);

	while (1) {
		s1 = str[0];
		s2 = str[1];
		n1 = stoi(s1);
		n2 = stoi(s2);
		num = n1 + n2;
		cnt++;

		if (num < 10) {
			str = s2 + to_string(num);
			num = stoi(str);
		}
		else {
			str = s2 + to_string(num)[1];
			num = stoi(str);
		}
		if (num == firstNum) break;
	}
	cout << cnt << endl;
	return 0;
}