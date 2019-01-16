#include <iostream>
#define INF	2000000000

using namespace std;

int pos[1000002];

int main() {
	int testcase;
	cin >> testcase;
	for (int T = 1; T <= testcase; T++) {
		int N, K;
		int pre, cur = 0, next, jmp = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> pos[i];
		pos[N + 1] = INF;
		cin >> K;
		while (cur < N) {
			next = pos[cur] + K;
			pre = cur;
			while (pos[cur] <= next)
				cur++;
			cur--;
			if (pre == cur) {
				jmp = -1; break;
			}
			jmp++;
		}
		cout << "Case #" << T << '\n' << jmp << '\n';
	}
	return 0;
}