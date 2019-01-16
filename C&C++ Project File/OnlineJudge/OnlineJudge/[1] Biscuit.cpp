#include<iostream>

int main() {
	int K, N, M;
	std::cin >> K >> N >> M;
	int sol = (K*N) - M;
	if (sol > 0) std::cout << sol;
	else std::cout << 0;
	return 0;
}