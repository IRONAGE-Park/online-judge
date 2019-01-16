#include<iostream>
#include<string>

using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int rep;
		string str;
		cin >> rep >> str;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < rep; j++) {
				cout << str[i];
			}
		}
		cout << '\n';
	}
	return 0;
}