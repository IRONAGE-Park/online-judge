#include<iostream>

int main() {
	int C, R, N;
	std::cin >> C >> R >> N;
	if (N > C*R) std::cout << 0 << std::endl;
	else {
		int i;
		int x = 1, y = 0;
		int minus = 0;
		while (1) {
			for (i = 0; (i < R - minus) && (N > 0); i++, N--, y++);
			minus++;
			for (i = 0; (i < C - minus) && (N > 0); i++, N--, x++);
			for (i = 0; (i < R - minus) && (N > 0); i++, N--, y--);
			minus++;
			for (i = 0; (i < C - minus) && (N > 0); i++, N--, x--);
			if (N == 0) break;
		}
		std::cout << x << " " << y << std::endl;
	}
	return 0;
}