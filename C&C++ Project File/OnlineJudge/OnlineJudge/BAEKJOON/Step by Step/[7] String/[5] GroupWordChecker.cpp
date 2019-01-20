#include<iostream>
#include<string>
#include<vector>
#define NUM 26

using namespace std;

int main() {
	int testcase, cnt = 0;
	cin >> testcase;
	while (testcase--) {
		char pre;
		bool result = true;
		string str;
		vector<bool> v(NUM, false);
		v.reserve(NUM);
		cin >> str;

		pre = str[0];
		for (int i = 1; i < str.length(); i++) {
			if (str[i - 1] != str[i]) {
				v.at(str[i - 1] - 97) = true;
				if (v.at(str[i] - 97)) {
					result = false;
					break;
				}
			}
			pre = str[i];
		}
		if (result) cnt++;
	}
	cout << cnt << endl;
	return 0;
}