#include<iostream>
#include<string>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	do {
		string str = to_string(n); // 132
		bool check = true;
		int dif, pre_dif; // dif = �ι�°�� ����° �ڸ��� ���� ����. pre_dif = ù��°�� �ι�°�� ����.
		for (int i = 1; i < str.length(); i++) {
			dif = str[i] - str[i-1];
			if (i != 1) {
				if (dif != pre_dif) { // ù��°�� �ι�°�� ���̰�, �ι�°�� ����°�� ���̶� �ٸ� ���.
					check = false;
				}
			}
			pre_dif = dif;
		}
		if (check) cnt++;
	} while (n--);
	cout << cnt - 1 << endl;
	return 0;
}