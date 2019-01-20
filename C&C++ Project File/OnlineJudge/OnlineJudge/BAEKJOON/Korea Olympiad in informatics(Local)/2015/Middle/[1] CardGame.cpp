#include<iostream>

int main() {
	int card[2][10];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 10; j++)
			std::cin >> card[i][j];
	int win_A = 0, win_B = 0;
	for (int i = 0; i < 10; i++) {
		if (card[0][i] > card[1][i]) win_A++;
		else if (card[0][i] < card[1][i]) win_B++;
	}
	if (win_A > win_B) std::cout << 'A';
	else if (win_A < win_B) std::cout << 'B';
	else std::cout << 'D';
	return 0;
}