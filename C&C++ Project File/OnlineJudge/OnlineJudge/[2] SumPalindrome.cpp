#include<iostream>
#include<vector>
#include<string>
#define INF 0xFFFFFF
#define MAX 10001
#define TEN 10

using namespace std;

typedef struct { int cnt; vector<int> list; }Data;

Data DP[MAX];

bool Palindrome(int num) { // Ư�� ���� ȸ������ �ƴ��� �Ǻ�
	string str(::to_string(num));
	for (int i = 0, j = str.length() - 1; j >= 0; i++, j--) {
		if (str[i] != str[j]) return false;
	}
	return true;
}

void MakeTable() {
	vector<int> palin; // ȸ���� ���� ������ ����Ʈ
	palin.reserve(MAX);
	DP[0].cnt = 0; palin.push_back(1);
	for (int i = 1; i < TEN; i++) { DP[i].cnt = 1; DP[i].list.push_back(i); } // 1���� 9������ ��� ȸ���̶� Ƚ�� 1
	for (int i = TEN; i < MAX; i++) if (Palindrome(i)) {
		DP[i].cnt = 1;
		DP[i].list.push_back(i); 
		palin.push_back(i); 
	} // ȸ���� �� ����
	int p = 0;
	for (int i = 10; i < MAX; i++) {
		if (!Palindrome(i)) { // ȸ���� �ƴϸ� DP Setting.
			if (palin[p + 1] < i) p++;
			int min = INF;
			vector<int> minList;
			for (int temp = p; temp >= 0; temp--) 
				if (DP[palin[temp]].cnt + DP[i - palin[temp]].cnt < min) {
					min = DP[palin[temp]].cnt + DP[i - palin[temp]].cnt;
					minList = DP[i - palin[temp]].list;
					minList.push_back(palin[temp]);
				}
			DP[i].cnt = min;
			DP[i].list = minList;
			minList.clear();
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;
	MakeTable();
	for (int T = 1; T <= testcase; T++) {
		int N;
		cin >> N;
		/* INPUT DATA */

		cout << "Case #" << T << '\n' << DP[N].cnt;
		for (int i = DP[N].list.size() - 1; i >= 0; i--) cout << " " << DP[N].list[i];
		cout << '\n';
	}
	return 0;
}