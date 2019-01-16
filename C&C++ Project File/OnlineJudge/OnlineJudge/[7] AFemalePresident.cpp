#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> floor;
	vector< vector<int> > apart;
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int N, K;
		cin >> K >> N;
		floor.resize(N + 1);
		apart.resize(K + 1, floor);
		for (int i = 1; i <= N; i++) apart[0][i] = i;
		for (int i = 1; i <= K; i++)
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= j; k++)
					apart[i][j] += apart[i - 1][k];
		cout << apart[K][N] << '\n';
		floor.clear();
		apart.clear();
	}
	return 0;
}