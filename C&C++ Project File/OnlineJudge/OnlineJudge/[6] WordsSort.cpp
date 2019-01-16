#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	return a < b;
}

template <typename Iter>
void Print(Iter begin, Iter end) {
	string pre("");
	for (; begin != end; begin++) {
		if (pre != *begin) {
			cout << *begin << '\n';
			pre = *begin;
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<string> list;
	list.resize(N);
	for (int i = 0; i < N; i++)
		cin >> list[i];
	sort(list.begin(), list.end(), compare);
	Print(list.begin(), list.end());
	return 0;
}