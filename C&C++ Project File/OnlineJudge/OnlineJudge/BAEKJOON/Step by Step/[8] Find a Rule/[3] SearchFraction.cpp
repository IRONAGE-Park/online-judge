#include<iostream>
#define UP 1

using namespace std;

void Solution(int N) { // 그에 해당하는 지그재그 분수 값 찾기
	int cnt = 1, start;
	for (start = 0; start < N; start += cnt++); // 대략적인 위치 찾음
	int numerator, denomirator; // 분자 분모
	if (cnt % 2 == UP) {
		numerator = 1, denomirator = cnt - 1;
	}
	else {
		numerator = cnt - 1, denomirator = 1;
	}
	// 초기값 세팅
	start -= cnt - 1;
	for (; start < N - 1; start++) {
		if (cnt % 2 == UP) {
			numerator++, denomirator--;
		}
		else {
			numerator--, denomirator++;
		}
	}

	cout << numerator << '/' << denomirator << '\n';
}

int main() {
	int N;
	cin >> N;
	Solution(N);
	return 0;
}