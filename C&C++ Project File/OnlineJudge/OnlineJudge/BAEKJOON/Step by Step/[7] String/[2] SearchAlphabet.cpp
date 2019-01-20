#include<iostream>
#include<string>
#include<vector>
#define NUM 26

using namespace std;

int main() {
	string str;
	vector<int> v(NUM, -1);
	v.reserve(NUM);
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (v.at(str[i] - 97) == -1) v.at(str[i] - 97) = i;
	}
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) != -1) cout << v.at(i) << " ";
		else cout << "-1 ";
	}
	return 0;
}