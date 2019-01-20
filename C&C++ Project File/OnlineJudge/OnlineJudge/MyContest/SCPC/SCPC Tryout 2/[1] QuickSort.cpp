#include<iostream>
#include<vector>
#define INF 0xFFFFFFF

using namespace std;

typedef struct {
	int num; // 그 인덱스의 숫자
	bool left, right; // Check 변수
	int leftMAX, rightMIN; // 왼쪽에서 가장 큰 것, 오른쪽에서 가장 작은 것
}Node;

int main() {
	int testcase;
	cin >> testcase;
	for (int T = 1; T <= testcase; T++) {
		int N;
		cin >> N;
		vector<Node> list;
		list.reserve(N);
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			Node node = { num, false, false, 0, INF };
			list.push_back(node);
		}
		list[0].leftMAX = list[0].num, list[0].left = true; // 가장 왼쪽에 있는 수 초기화.
		for (int i = 1; i < N; i++) { // 왼쪽 기준으로 확인
			if (list[i - 1].leftMAX > list[i].num)  // 이 전의 수보다 지금 수가 더 작으면
				list[i].left = false, list[i].leftMAX = list[i - 1].leftMAX;
			else
				list[i].left = true, list[i].leftMAX = list[i].num;
		}
		list[N - 1].rightMIN = list[N - 1].num, list[N - 1].right = true; // 가장 오른쪽에 있는 수 초기화.
		for (int i = N - 2; i >= 0; i--) { // 오른쪽 기준으로 확인
			if (list[i].num > list[i + 1].rightMIN)  // 이 전의 수보다 지금 수가 더 크면
				list[i].right = false, list[i].rightMIN = list[i + 1].rightMIN;
			else
				list[i].right = true, list[i].rightMIN = list[i].num;
		}
		int Answer = 0;
		for (int i = 0; i < N; i++) {
			if (list[i].left && list[i].right) Answer++;
		}
		cout << "Case #" << T << '\n' << Answer << '\n';
		list.clear();
	}
	return 0;
}