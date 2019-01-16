#include<iostream>

using namespace std;

int Solution(int H, int W, int N) { // 어느 방에 배정될지 계산
	int room = 0, nh = 0;
	for (int i = 0; i < N; i++) {
		if (i % H == 0) {
			room %= 100;
			room += 101;
		}
		else 
			room += 100;
	}
	return room;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int H, W, N;
		cin >> H >> W >> N;
		cout << Solution(H, W, N) << '\n';
	}
	return 0;
}