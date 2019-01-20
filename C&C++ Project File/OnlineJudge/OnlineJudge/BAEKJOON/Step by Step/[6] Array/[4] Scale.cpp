#include<iostream>
#include<string>

using namespace std;

int main() {
	string asc("1 2 3 4 5 6 7 8"), desc("8 7 6 5 4 3 2 1");
	string ans;
	getline(cin, ans);
	if (ans == asc) cout << "ascending" << endl;
	else if (ans == desc) cout << "descending" << endl;
	else cout << "mixed" << endl;
	return 0;
}