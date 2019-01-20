#include<iostream>
#include<vector>
#define INF 0xFFFFFFF

using namespace std;

typedef struct {
	int num; // �� �ε����� ����
	bool left, right; // Check ����
	int leftMAX, rightMIN; // ���ʿ��� ���� ū ��, �����ʿ��� ���� ���� ��
}Node;

int main() {
	int testcase;
	cin >> testcase;
	for (int T = 1; T <= testcase; T++) {
		int N;
		cin >> N;
		vector<Node> list;
		list.reserve(N);
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			Node node = { num, false, false, 0, INF };
			list.push_back(node);
		}
		list[0].leftMAX = list[0].num, list[0].left = true; // ���� ���ʿ� �ִ� �� �ʱ�ȭ.
		for (int i = 1; i < N; i++) { // ���� �������� Ȯ��
			if (list[i - 1].leftMAX > list[i].num)  // �� ���� ������ ���� ���� �� ������
				list[i].left = false, list[i].leftMAX = list[i - 1].leftMAX;
			else
				list[i].left = true, list[i].leftMAX = list[i].num;
		}
		list[N - 1].rightMIN = list[N - 1].num, list[N - 1].right = true; // ���� �����ʿ� �ִ� �� �ʱ�ȭ.
		for (int i = N - 2; i >= 0; i--) { // ������ �������� Ȯ��
			if (list[i].num > list[i + 1].rightMIN)  // �� ���� ������ ���� ���� �� ũ��
				list[i].right = false, list[i].rightMIN = list[i + 1].rightMIN;
			else
				list[i].right = true, list[i].rightMIN = list[i].num;
		}
		int Answer = 0;
		for (int i = 0; i < N; i++) {
			if (list[i].left && list[i].right) Answer++;
		}
		cout << "Case #" << T << '\n' << Answer << '\n';
		list.clear();
	}
	return 0;
}