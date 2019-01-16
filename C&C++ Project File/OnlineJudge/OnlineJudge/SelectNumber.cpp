#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
	int testcase;
	cin >> testcase;
	for (int i = 1; i <= testcase; i++) {
		int N, answer = 0;
		cin >> N;
		while (N--) {
			int val;
			cin >> val;
			answer = answer ^ val;
		}
		cout << "Case #" << i << '\n' << answer << '\n';
	}
	return 0;
}