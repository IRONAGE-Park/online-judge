#include<iostream>
#include<vector>
#define MAX 10001

using namespace std;

int main() {
	int N; // Data�� ����
	cin >> N;
	vector<int> digit(MAX);
	while (N--) {
		int num;
		cin >> num;
		digit[num]++;
		// �� ���ڰ� �� �� ���Դ��� Counting.
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < digit[i]; j++) {
			cout << i << '\n';
		}
	} // Counting Data�� �̿��Ͽ� ������� ���.
	return 0;
}