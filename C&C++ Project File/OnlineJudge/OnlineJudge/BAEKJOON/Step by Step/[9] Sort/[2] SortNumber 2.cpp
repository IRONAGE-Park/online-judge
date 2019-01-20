#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> list;
int N;

void PrintList() {
	for (int i = 0; i < N; i++)
		cout << list[i] << ' ';
	cout << '\n';
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}
	sort(list.begin(), list.end());
	PrintList();
	return 0;
}