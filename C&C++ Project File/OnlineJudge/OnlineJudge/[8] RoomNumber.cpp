#include<iostream>
#include<string>
#include<vector>
#define DIGIT 10

using namespace std;

int main() {
	string rNum;
	cin >> rNum;
	
	vector<int> cnt;
	cnt.resize(DIGIT);
	for (int i = 0; i < rNum.length(); i++)
		cnt[rNum[i] - 48]++;
	cnt[6] += cnt[9];
	if (cnt[6] % 2 == 1) 
		cnt[6] = (cnt[6] / 2) + 1;
	else cnt[6] = cnt[6] / 2;
	int max = 0;
	for (int i = 0; i < DIGIT - 1; i++)
		if (max < cnt[i]) max = cnt[i];
	cout << max;
	return 0;
}