#include<iostream>
#include<string>

using namespace std;

int time(char t) {
	if (t >= 'W') return 10;
	else if (t >= 'T') return 9;
	else if (t >= 'P') return 8;
	else if (t >= 'M') return 7;
	else if (t >= 'J') return 6;
	else if (t >= 'G') return 5;
	else if (t >= 'D') return 4;
	else return 3;
}

int main() {
	string str;
	cin >> str;
	int t = 0;
	for (int i = 0; i < str.length(); i++) {
		t += time(str[i]);
	}
	cout << t;
	return 0;
}