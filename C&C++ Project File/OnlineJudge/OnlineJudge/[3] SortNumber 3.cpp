#include<iostream>
#include<vector>
#define MAX 10001

using namespace std;

int main() {
	int N; // Data의 갯수
	cin >> N;
	vector<int> digit(MAX);
	while (N--) {
		int num;
		cin >> num;
		digit[num]++;
		// 그 숫자가 몇 번 나왔는지 Counting.
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < digit[i]; j++) {
			cout << i << '\n';
		}
	} // Counting Data를 이용하여 순서대로 출력.
	return 0;
}