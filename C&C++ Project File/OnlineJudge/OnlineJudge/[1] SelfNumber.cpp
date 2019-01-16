#include<iostream>
#include<string>

using namespace std;

bool exist[10000];

void SelfNumber(int num) {
	string change;
	change = to_string(num);
	for (int i = 0; i < change.size(); i++) {
		num += change[i] - 48;
	}
	exist[num - 1] = true;
}

int main() {
	for (int i = 1; i < 10000; i++)
		SelfNumber(i);

	for (int i = 0; i < 10000; i++) {
		if (!exist[i]) cout << i + 1 << endl;
	}

	return 0;
}