#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream inp("dish.inp");
	ofstream out("dish.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int len, height = 0;
		char c, before = '\0'; // before의 경우 첫 계산을 위해 기본 값으로 초기화
		inp >> len;
		while (len--) { // 처음 주어진 길이만큼 반복 입력
			inp >> c; // 문자(그릇)을 입력 받고,
			if (c != before) height += 10; // 이전 그릇과 입력 받은 그릇이 다르면 높이가 10 추가.
			else height += 5; // 같은 경우 높이 5 추가
			before = c; // 이전 그릇(괄호)의 정보 저장
		}
		out << height << '\n'; // 계산된 값 출력
	}
	inp.close();
	out.close();
	return 0;
}