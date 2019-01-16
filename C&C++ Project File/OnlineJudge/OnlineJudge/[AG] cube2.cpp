#include<iostream>
#include<fstream>
#define INF 0xFFFFFFF
#define MAX 201
using namespace std;

int cube[MAX][MAX][MAX]; // 각 W, L, H에 대한 큐브의 최소 갯수

void MIN(int *min, int value) {
	if (*min > value)
		*min = value;
}

void input(int i, int j, int k, int min) { // i, j, k로 나올 수 있는 경우의 수 모두 입력
	cube[i][j][k] = min;
	cube[i][k][j] = min;
	cube[j][i][k] = min;
	cube[j][k][i] = min;
	cube[k][i][j] = min;
	cube[k][j][i] = min;
}

void DP() {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= j; k++) {
				if (!(i == j && i == k)) {
					int min = INF;
					for (int ci = i / 2; ci < i; ci++) MIN(&min, cube[ci][j][k] + cube[i - ci][j][k]);
					for (int cj = j / 2; cj < j && j > 1; cj++) MIN(&min, cube[i][cj][k] + cube[i][j - cj][k]);
					for (int ck = k / 2; ck < k && k > 1; ck++) MIN(&min, cube[i][j][ck] + cube[i][j][k - ck]);
					input(i, j, k, min);
				}
				else cube[i][j][k] == 1;
			}
		}
	}
}

int main() {
	ifstream inp("cube.inp");
	ofstream out("cube.out");
	DP();
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int W, L, H;
		inp >> W >> L >> H;
		out << cube[W][L][H] << '\n';
	}
	inp.close();
	out.close();
	return 0;
}