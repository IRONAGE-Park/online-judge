#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int CountingData(vector<int> list) {
	int maxCnt = 1, cnt = 1;
	vector<int> cntList;
	for (int i = 0; i < list.size() - 1; i++) {
		if (list[i] == list[i + 1]) // 다음 값과 같은 값이면
			cnt++;
		else
			cnt = 1;

		if (cnt > maxCnt) {
			maxCnt = cnt;
			cntList.clear();
			cntList.push_back(list[i]);
		}
		else if (cnt == maxCnt) {
			cntList.push_back(list[i]);
		}
	}
	if (list.size() == 1) return list[0];
	if (cntList.size() != 1) return cntList[1];
	else return cntList[0];
}

int main() {
	int N, sum = 0;
	cin >> N;
	vector<int> list(N);
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		sum += list[i];
	}
	cout.setf(ios::fixed);
	cout.precision(0);
	double avg = (double) sum /  (double) N;
	cout << avg << '\n'; // 산술평균
	sort(list.begin(), list.end()); // 퀵정렬
	cout << list[N / 2] << '\n';
	cout << CountingData(list) << '\n'; // 최빈값
	cout << list[N - 1] - list[0] << '\n'; // 범위
	return 0;
}