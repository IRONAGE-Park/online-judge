#include<iostream>
#include<fstream>
#define EVEN 0

using namespace std;

int Type1_1(int N, int M, int K);
int Type1_2(int N, int M, int K);
int Type1_3(int N, int M, int K);
int Type1_4(int N, int M, int K);
int Type2_1(int N, int M, int K);
int Type2_2(int N, int M, int K);
int Type2_3(int N, int M, int K);
int Type2_4(int N, int M, int K);

int main() {
	ifstream inp("main.inp");
	ofstream out("main.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int N, M, T, S, K, sol;
		inp >> N >> M >> T >> S >> K;
		/* N x M의 격자에서, T = Type, S = 출발점, K는 이동거리 */
		switch (T) {
		case 1: // Type 1번(수평방향 반복 이동)
			switch (S) {
			case 1: sol = Type1_1(N, M, K); break;
			case 2: sol = Type1_2(N, M, K); break;
			case 3: sol = Type1_3(N, M, K); break;
			case 4: sol = Type1_4(N, M, K); break;
			}
		case 2: // Type 2번(수직방향 반복 이동)
			switch (S) {
			case 1: sol = Type2_1(N, M, K); break;
			case 2: sol = Type2_2(N, M, K); break;
			case 3: sol = Type2_3(N, M, K); break;
			case 4: sol = Type2_4(N, M, K); break;
		}
		out << sol << '\n';
	}
	return 0;
}

int Type1_1(int N, int M, int K) { // Type 1의 출발점 좌상
	int vertical = (K - 1) / M, sol; // 우선 수직으로 몇 칸 내려갔는지 확인.
	sol = M * (vertical + 1); // 우선 그 줄의 최대치만큼 더해준 후
	if (vertical % 2 == EVEN) {
		/* 짝수 칸만큼 내려갔으면, 왼쪽에서 오른쪽으로 이동 */
		sol -= (M - (K % M));
		if (!(K % M)) sol += M; // 마지막 처리
	}
	else {
		/* 홀수 칸만큼 내려갔으면, 오른쪽에서 왼쪽으로 이동 */
		sol -= (K - 1) % M; // 나머지만큼 빼줌
	}
	return sol;
}
int Type1_2(int N, int M, int K) { // Type 1의 출발점 우상
	int vertical = (K - 1) / M, sol; // 우선 수직으로 몇 칸 내려갔는지 확인.
	sol = M * (vertical + 1); // 그 줄의 가장 오른쪽으로 이동시킨 후
	if (vertical % 2 == EVEN) {
		/* 짝수 칸만큼 내려갔으면, 오른쪽에서 왼쪽으로 이동 */
		sol -= (K - 1) % M; // 나머지만큼 빼줌
	}
	else {
		/* 홀수 칸만큼 내려갔으면, 왼쪽에서 오른쪽으로 이동 */
		sol -= (M - (K % M));
		if (!(K % M)) sol += M; // 마지막 처리
	}
	return sol;
}
int Type1_3(int N, int M, int K) { // Type 1의 출발점 우하
	int vertical = (K - 1) / M, sol = N * M; // 우선 수직으로 몇 칸 올라갔는지 확인.
	sol -= M * vertical; // 우선 그 줄의 최대치만큼 빼준 후
	if (vertical % 2 == EVEN) {
		/* 짝수 칸만큼 올라갔으면, 오른쪽에서 왼쪽으로 이동 */
		sol -= (K - 1) % M; // 나머지만큼 빼줌
	}
	else {
		/* 홀수 칸만큼 올라갔으면, 왼쪽에서 오른쪽으로 이동 */
		sol -= (M - (K % M));
		if (!(K % M)) sol += M; // 마지막 처리
	}
	return sol;
}
int Type1_4(int N, int M, int K) { // Type 1의 출발점 좌하
	int vertical = (K - 1) / M, sol = N * M; // 우선 수직으로 몇 칸 내려갔는지 확인.
	sol -= M * vertical; // 그 줄의 가장 오른쪽으로 이동시킨 후
	if (vertical % 2 == EVEN) {
		/* 짝수 칸만큼 올라갔으면, 왼쪽에서 오른쪽으로 이동 */
		sol -= (M - (K % M));
		if (!(K % M)) sol += M; // 마지막 처리
	}
	else {
		/* 홀수 칸만큼 올라갔으면, 오른쪽에서 왼쪽으로 이동 */
		sol -= (K - 1) % M; // 나머지만큼 빼줌
	}
	return sol;
}

int Type2_1(int N, int M, int K) { // Type 2의 출발점 좌상
	int pararel = (K - 1) / N, sol = 1; // 우선 우측으로 몇 칸 갔는지 확인.
	sol += pararel; // 이동한 거리만큼 더해준 후
	if (pararel % 2 == EVEN) {
		/* 짝수 칸만큼 갔으면, 위쪽에서 아래쪽으로 이동 */
		sol += ((K - 1) % N) * M;
	}
	else {
		/* 홀수 칸만큼 갔으면, 아래쪽에서 위쪽으로 이동 */
		sol += ((N - 1) * M);
		sol -= ((K - 1) % N) * M;
	}
	return sol;
}
int Type2_2(int N, int M, int K) { // Type 2의 출발점 우상
	int pararel = (K - 1) / N, sol = M; // 우선 좌측으로 몇 칸 갔는지 확인.
	sol -= pararel; // 이동한 거리만큼 빼준 후
	if (pararel % 2 == EVEN) {
		/* 짝수 칸만큼 갔으면, 위쪽에서 아래쪽으로 이동 */
		sol += ((K - 1) % N) * M;
	}
	else {
		/* 홀수 칸만큼 갔으면, 아래쪽에서 위쪽으로 이동 */
		sol += ((N - 1) * M);
		sol -= ((K - 1) % N) * M;
	}
	return sol;
}
int Type2_3(int N, int M, int K) { // Type 2의 출발점 우하
	int pararel = (K - 1) / N, sol = N * M; // 우선 좌측으로 몇 칸 갔는지 확인.
	sol -= pararel; // 이동한 거리만큼 빼준 후
	if (pararel % 2 == EVEN) {
		/* 짝수 칸만큼 갔으면, 아래쪽에서 위쪽으로 이동 */
		sol -= ((K - 1) % N) * M;
	}
	else {
		/* 홀수 칸만큼 갔으면, 위쪽에서 아래쪽으로 이동 */
		sol -= ((N - 1) * M);
		sol += ((K - 1) % N) * M;
	}
	return sol;
}
int Type2_4(int N, int M, int K) { // Type 2의 출발점 좌하
	int pararel = (K - 1) / N, sol = ((N - 1) * M) + 1; // 우선 좌측으로 몇 칸 갔는지 확인.
	sol += pararel; // 이동한 거리만큼 빼준 후
	if (pararel % 2 == EVEN) {
		/* 짝수 칸만큼 갔으면, 아래쪽에서 위쪽으로 이동 */
		sol -= ((K - 1) % N) * M;
	}
	else {
		/* 홀수 칸만큼 갔으면, 위쪽에서 아래쪽으로 이동 */
		sol -= ((N - 1) * M);
		sol += ((K - 1) % N) * M;
	}
	return sol;
}