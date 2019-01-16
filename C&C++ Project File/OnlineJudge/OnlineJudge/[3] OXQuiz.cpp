#include<iostream>
#include<string>

using namespace std;

int Solution(string str) {
	int answer = 0;
	int zeroCnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'O') {
			zeroCnt++;
			answer += zeroCnt;
		}
		else zeroCnt = 0;
	}
	return answer;
}

int main() {
	
	int testcase;
	string str;
	cin >> testcase;
	getline(cin, str);
	while (testcase--) {
		getline(cin, str);
		// charÀÏ °æ¿ì cin.getline(str, size);
		cout << Solution(str) << endl;
	}
	return 0;
}