#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int main() {
	map<int, int> m;
	

	for (int i = 0; i < 1000; i++) {m[i] = i;}

	cout << m.at(0);
}