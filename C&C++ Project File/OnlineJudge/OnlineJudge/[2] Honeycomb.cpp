#include<iostream>
#define SIX 6

using namespace std;

typedef long long int lint;

lint Calculate(lint N) { // 지나가는 방 횟수 계산
	lint cnt = 1;
	for (lint room = 1; room < N; room += SIX * cnt++);
	return cnt;
}

int main() {
	lint N;
	cin >> N;
	cout << Calculate(N);
	return 0;
}