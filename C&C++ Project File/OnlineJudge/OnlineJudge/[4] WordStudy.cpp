#include<iostream>
#include<string>
#include<vector>
#define NUM 26

using namespace std;

char Max(vector<int> v) {
	int max = 0;
	bool only = true;
	for (int i = 1; i < v.size(); i++) {
		if (v.at(max) < v.at(i)) {
			max = i;
			only = true;
		}
		else if (v.at(max) == v.at(i)) {
			only = false;
		}
	}
	if (only) return (char)(max + 65);
	else return '?';
}

int main() {
	string str;
	vector<int> v(NUM);
	v.reserve(NUM);

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] - 65 > 25) {
			v.at(str[i] - 97)++;
		}
		else v.at(str[i] - 65)++;
	}
	cout << Max(v) << endl;
	return 0;
}