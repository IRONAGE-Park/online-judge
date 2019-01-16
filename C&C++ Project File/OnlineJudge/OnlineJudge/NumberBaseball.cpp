#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> bucket;

void Init() {
	for (char i = '1'; i <= '9'; i++) {
		for (char j = '1'; j <= '9'; j++) {
			if (i == j) continue;
			for (char k = '1'; k <= '9'; k++) {
				if (i == k || j == k) continue;
				string s = "";
				s += i;
				s += j;
				s += k;
				bucket.push_back(s);
			}
		}
	}
}

int StrikeCheck(string operend, string op) {
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		if (operend[i] == op[i]) cnt++;
	return cnt;
}

int BallCheck(string operend, string op) {
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i != j && operend[j] == op[i]) cnt++;
	return cnt;
}

void QuestionUpdate(string num, int strike, int ball) {
	vector<string> newBucket;
	for (int i = 0; i < bucket.size(); i++) {
		if (StrikeCheck(bucket[i], num) == strike && BallCheck(bucket[i], num) == ball)
			newBucket.push_back(bucket[i]);
	}
	bucket = newBucket;
}

int main() {
	int Q;
	cin >> Q;
	Init();
	while (Q--) {
		string num;
		int strike, ball;
		cin >> num >> strike >> ball;
		QuestionUpdate(num, strike, ball);
	}
	cout << bucket.size();
	return 0;
}