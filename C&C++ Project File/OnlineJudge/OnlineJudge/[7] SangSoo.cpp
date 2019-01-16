#include<iostream>
#include<string>

using namespace std;

int Reverse(string str) {
	string r_str = "";
	for (int i = str.length() - 1; i >= 0; i--) {
		r_str += str[i];
	}
	return stoi(r_str);
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int num1 = Reverse(str1), num2 = Reverse(str2);
	if (num1 > num2) cout << num1;
	else cout << num2;
	return 0;
}