#include<iostream>
#include<fstream> 

using namespace std;

int **block, N;

void Update(int i, int j) { 
	if (i < N && i >= 0 && j <= i && j >= 0) { 
		// 그 블록이 갱신가능한 위치의 블록일 때,
		if (block[i][j] == -1) { // 갱신이 필요한 블록이면, 
			bool update = false; 
			if (j - 1 >= 0) { // 왼쪽에 대해 안전하게 접근 가능할 때
				if (i - 1 >= 0) { // 위쪽에 대해 안전하게 접근 가능하면,
					if (block[i - 1][j - 1] != -1 && block[i][j - 1] != -1) { // 왼쪽 위, 왼쪽 블록을 통해 알아냄.
						block[i][j] = block[i - 1][j - 1] - block[i][j - 1]; 
						if (block[i][j] < 0) block[i][j] += 100; // 0보다 작으면 100 더해줌 
						update = true; 
					}
				} 
			} 
			if (j + 1 <= i + 1 && !update) { // 오른쪽 아래에 대해 안전하게 접근 가능할 때 
				if (i - 1 >= 0 && j + 1 <= i) { // 위쪽과 오른쪽에 대해 안전하게 접근 가능하면, 
					if (block[i - 1][j] != -1 && block[i][j + 1] != -1) { // 위, 오른쪽 블록을 통해 알아냄.
						block[i][j] = block[i - 1][j] - block[i][j + 1];
						if (block[i][j] < 0) block[i][j] += 100; // 0보다 작으면 100 더해줌 
						update = true;
					}
				}
				if (i + 1 < N && !update) { // 아래쪽에 대해 안전하게 접근 가능하면,
					if (block[i + 1][j] != -1 && block[i + 1][j + 1] != -1) {
						// 아래, 오른쪽 아래 블록을 통해 알아냄.
						block[i][j] = (block[i + 1][j] + block[i + 1][j + 1]) % 100;
						update = true;
					}
				}
			}
			if (update) { // 갱신되었다면,
				Update(i - 1, j - 1); 
				Update(i - 1, j);
				Update(i, j - 1); 
				Update(i + 1, j);
				Update(i, j + 1);
				Update(i + 1, j + 1);
				/* 다른 6방향 모두 갱신 가능한지 확인 */ 
			}
		}
	}
} 

int main() { 
	//ifstream inp("block.inp");
	//ofstream out("block.out"); 
	ifstream inp("input.txt");
	ofstream out("output.txt");
	int testcase;
	inp >> testcase;
	while (testcase--) { 
		inp >> N; 
		block = new int*[N];
		for (int i = 0; i < N; i++) block[i] = new int[i + 1]; 
		/* Allocation Array */ 
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= i; j++) 
				inp >> block[i][j]; 
		/* Input Data */ 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j <= i; j++) 
				if (block[i][j] == -1)
					Update(i, j); 
		/* All Block Update. */ 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++)
				out << block[i][j] << ' '; 
			out << '\n'; 
		} 
		/* Output Data */ 
		for (int i = 0; i < N; i++) 
			delete[] block[i];
		delete[] block; 
		/* Initialized */ 
	}
	inp.close(); 
	out.close(); 
	return 0;
}