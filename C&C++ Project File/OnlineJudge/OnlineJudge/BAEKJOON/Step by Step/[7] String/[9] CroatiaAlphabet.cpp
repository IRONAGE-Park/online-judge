#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'c' && i != str.length() - 1) {
			if ((str[i + 1] == '=' || str[i + 1] == '-')) {
				i++;
			}
		}
		else if (str[i] == 'd') {
			if (str[i + 1] == 'z' && str[i + 2] == '=' && i != str.length() - 2) {
				i += 2;
			}
			else if (str[i + 1] == '-' && i != str.length() - 1) {
				i++;
			}
		}
		else if (str[i] == 'l' && i != str.length() - 1) {
			if (str[i + 1] == 'j') {
				i++;
			}
		}
		else if (str[i] == 'n' && i != str.length() - 1) {
			if (str[i + 1] == 'j') {
				i++;
			}
		}
		else if (str[i] == 's' && i != str.length() - 1) {
			if (str[i + 1] == '=') {
				i++;
			}
		}
		else if (str[i] == 'z' && i != str.length() - 1) {
			if (str[i + 1] == '=') {
				i++;
			}
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}