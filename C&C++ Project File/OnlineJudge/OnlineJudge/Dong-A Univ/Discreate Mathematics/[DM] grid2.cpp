#include<iostream>
#include<fstream>

enum VECTOR { UP, DOWN, LEFT, RIGHT };

using namespace std;

int Solution(int N, int M, int type, int init, int K, int vector) { // ���� ��ġ ã�� �Լ�
	for (int i = 1; ; i++) {
		if (vector == UP) { // ���� ���� ����
			if (K <= N - (i / 2)) {
				init -= K * M;
				break;
			}
			else {
				init -= (N - (i / 2)) * M;
				K -= (N - (i / 2));
			}
			if(type == 3) vector = RIGHT;
			else vector = LEFT;
		}
		else if (vector == DOWN) { // �Ʒ��� ���� ����
			if (K <= N - (i / 2)) {
				init += K * M;
				break;
			}
			else {
				init += (N - (i / 2)) * M;
				K -= (N - (i / 2));
			}
			if (type == 3) vector = LEFT;
			else vector = RIGHT;
		}
		else if (vector == LEFT) { // �������� ���� ����
			if (K <= M - (i / 2)) {
				init -= K;
				break;
			}
			else {
				init -= M - (i / 2);
				K -= M - (i / 2);
			}
			if (type == 3) vector = UP;
			else vector = DOWN;
		}
		else { // ���������� ���� ����
			if (K <= M - (i / 2)) {
				init += K;
				break;
			}
			else {
				init += M - (i / 2);
				K -= M - (i / 2);
			}
			if (type == 3) vector = DOWN;
			else vector = UP;
		}
	}
	return init;
}

int main() {
	ifstream inp("grid2.inp");
	ofstream out("grid2.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int N, M, T, S, K, sol;
		inp >> N >> M >> T >> S >> K;
		switch (T) {
		case 3: // Type 3��
			switch (S) {
			case 1: sol = Solution(N, M, T, 0, K, RIGHT); break;
			case 2: sol = Solution(N, M, T, 0, K, DOWN); break;
			case 3: sol = Solution(N, M, T, (N * M) + 1, K, LEFT); break;
			case 4: sol = Solution(N, M, T, (N * M) + 1, K, UP); break;
			}
			break;
		case 4: // Type 4��
			switch (S) {
			case 1: sol = Solution(N, M, T, -M + 1, K, DOWN); break;
			case 2: sol = Solution(N, M, T, M + 1, K, LEFT); break;
			case 3: sol = Solution(N, M, T, (N + 1) * M, K, UP); break;
			case 4: sol = Solution(N, M, T, (N - 1) * M, K, RIGHT); break;
			}
			break;
		}
		out << sol << '\n';
	}
	inp.close();
	out.close();
	return 0;
}