#include<iostream>
#define UP 1

using namespace std;

void Solution(int N) { // �׿� �ش��ϴ� ������� �м� �� ã��
	int cnt = 1, start;
	for (start = 0; start < N; start += cnt++); // �뷫���� ��ġ ã��
	int numerator, denomirator; // ���� �и�
	if (cnt % 2 == UP) {
		numerator = 1, denomirator = cnt - 1;
	}
	else {
		numerator = cnt - 1, denomirator = 1;
	}
	// �ʱⰪ ����
	start -= cnt - 1;
	for (; start < N - 1; start++) {
		if (cnt % 2 == UP) {
			numerator++, denomirator--;
		}
		else {
			numerator--, denomirator++;
		}
	}

	cout << numerator << '/' << denomirator << '\n';
}

int main() {
	int N;
	cin >> N;
	Solution(N);
	return 0;
}