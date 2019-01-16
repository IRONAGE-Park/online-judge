#include<iostream>
#include<string>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	do {
		string str = to_string(n); // 132
		bool check = true;
		int dif, pre_dif; // dif = 두번째와 세번째 자릿수 간의 차이. pre_dif = 첫번째와 두번째의 차이.
		for (int i = 1; i < str.length(); i++) {
			dif = str[i] - str[i-1];
			if (i != 1) {
				if (dif != pre_dif) { // 첫번째와 두번째의 차이가, 두번째와 세번째의 차이랑 다를 경우.
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