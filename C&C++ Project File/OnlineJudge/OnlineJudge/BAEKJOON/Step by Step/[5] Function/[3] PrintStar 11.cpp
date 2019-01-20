#include<iostream>
#include<cstring>
#include<string>

using namespace std;

char board[10000][10000];

void Drawing_Tri(int x, int y) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 5; j++) {
			if (i == y + 2) board[i][j] = '*';
			else if (i - y + j - x == 2) board[i][j] = '*';
			else if (i - y == j - x - 2) board[i][j] = '*';
		}
	}
}

void Drawing(int size, int x, int y) {
	if (size == 3) {
		Drawing_Tri(x, y);
	}
	else if (size == 6) {
		Drawing_Tri(x + 3, y);
		Drawing_Tri(x, y + 3);
		Drawing_Tri(x + 6, y + 3);
	}
	else {
		Drawing(size / 2, x + (size / 2), y);
		Drawing(size / 2, x, y + (size / 2));
		Drawing(size / 2, x + size, y + (size / 2));
	}
}

void Printing(int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (size * 2) - 1; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
} // Ãâ·Â

int main() {
	int n;
	cin >> n;
	memset(board, ' ', sizeof(char) * 10000 * 10000);
	Drawing(n, 0, 0);
	Printing(n);
	return 0;
}