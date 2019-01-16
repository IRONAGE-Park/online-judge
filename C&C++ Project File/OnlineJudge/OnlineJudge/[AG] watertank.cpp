#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>

using namespace std;

typedef vector< vector<int> > Array;
typedef enum { UP, DOWN, LEFT, RIGHT }Vector;

int N, M, H; // N = 세로, M = 가로, H = 높이
Array horizontal, vertical, tank; // 가로 선, 세로 선의 정보와 탱크에 남은 물
bool check[1000][1000];

void Update(int i, int j, int vector, int preH) {
	if (i >= 0 && j >= 0 && i < N && j < M) {
		if (!check[i][j] && preH <= tank[i][j]) {
			bool change = true;
			if (vector == UP) { // 위쪽에서 내려올 때
				if (preH <= horizontal[i][j]) {
					if (tank[i][j] >= horizontal[i][j]) tank[i][j] = horizontal[i][j];
					else change = false;
				}
				else if (tank[i][j] > preH) tank[i][j] = preH;
			}
			else if (vector == DOWN) { // 아래쪽에서 올라올 때
				if (preH <= horizontal[i + 1][j]) {
					if (tank[i][j] >= horizontal[i + 1][j]) tank[i][j] = horizontal[i + 1][j];
					else change = false;
				}
				else if (tank[i][j] > preH) tank[i][j] = preH;
			}
			else if (vector == LEFT) { // 왼쪽에서 올 때
				if (preH <= vertical[i][j]) {
					if (tank[i][j] >= vertical[i][j]) tank[i][j] = vertical[i][j];
					else change = false;
				}
				else if (tank[i][j] > preH) tank[i][j] = preH;
			}
			else { // 오른쪽에서 올 때
				if (preH <= vertical[i][j + 1]) {
					if (tank[i][j] >= vertical[i][j + 1]) tank[i][j] = vertical[i][j + 1];
					else change = false;
				}
				else if (tank[i][j] > preH) tank[i][j] = preH;
			}
			check[i][j] = true;
			if (!change) return;
			if (vector != UP && horizontal[i][j] != -1) Update(i - 1, j, DOWN, tank[i][j]);
			if (vector != DOWN && horizontal[i + 1][j] != -1) Update(i + 1, j, UP, tank[i][j]);
			if (vector != LEFT && vertical[i][j] != -1) Update(i, j - 1, RIGHT, tank[i][j]);
			if (vector != RIGHT && vertical[i][j + 1] != -1) Update(i, j + 1, LEFT, tank[i][j]);
		}
	}
}

int Calculate() { // 연산
	for (int i = 0; i < M; i++) {
		if (horizontal[0][i] != -1) {
			if (tank[0][i] > horizontal[0][i]) {
				tank[0][i] = horizontal[0][i];
				//                Init();
				memset(check, false, sizeof(check));
				Update(0, i, UP, horizontal[0][i]);
			}
		}
		if (horizontal[N][i] != -1) {
			if (tank[N - 1][i] > horizontal[N][i]) {
				tank[N - 1][i] = horizontal[N][i];
				//                Init();
				memset(check, false, sizeof(check));
				Update(N - 1, i, DOWN, horizontal[N][i]);
			}
		}
	} // 윗 방향과 아랫 방향에서
	for (int i = 0; i < N; i++) {
		if (vertical[i][0] != -1) {
			if (tank[i][0] > vertical[i][0]) {
				tank[i][0] = vertical[i][0];
				//                Init();
				memset(check, false, sizeof(check));
				Update(i, 0, LEFT, vertical[i][0]);
			}
		}
		if (vertical[i][M] != -1) {
			if (tank[i][M - 1] > vertical[i][M]) {
				tank[i][M - 1] = vertical[i][M];
				//                Init();
				memset(check, false, sizeof(check));
				Update(i, M - 1, RIGHT, vertical[i][M]);
			}
		}
	} // 왼쪽 방향과 오른쪽 방향에서
	int answer = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			answer += tank[i][j];
	return answer;
}

int main() {
	ifstream inp("input.txt");
	ofstream out("output.txt");
	inp >> N >> M >> H;
	horizontal.resize(N + 1); vertical.resize(N); tank.resize(N);
	for (int i = 0; i < N + 1; i++) {
		horizontal[i].resize(M);
		for (int j = 0; j < M; j++)
			inp >> horizontal[i][j];
	}
	for (int i = 0; i < N; i++) {
		vertical[i].resize(M + 1);
		tank[i].resize(M, H);
		for (int j = 0; j < M + 1; j++)
			inp >> vertical[i][j];
	}
	/* Input Data */
	out << Calculate() << '\n';
	/* Output Data */
	inp.close();
	out.close();
	return 0;
}