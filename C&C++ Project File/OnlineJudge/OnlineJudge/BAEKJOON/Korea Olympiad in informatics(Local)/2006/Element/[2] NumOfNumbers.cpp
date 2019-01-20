#include<iostream>
#include<vector>
#include<string>
#define NUM 10

using namespace std;

template <typename Iter>
void Print(Iter begin, Iter end) {
	for (; begin != end; begin++) {
		cout << *begin << endl;
	}
}

int main() {
	int A, B, C;

	cin >> A >> B >> C;

	string num(to_string(A * B * C));
	vector<int> v(NUM, 0);

	for (int i = 0; i < num.length(); i++) {
		v.at(num.at(i) - 48)++;
	}
	Print(v.begin(), v.end());
	return 0;
}