#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	string num;
	cin >> num;
	vector<int> array;
	for (int i = 0; i < num.length(); i++) {
		array.push_back(num[i] - 48);
	}
	sort(array.begin(), array.end(), compare);
	for (int i = 0; i < array.size(); i++) {
		cout << array[i];
	}
	return 0;
}
