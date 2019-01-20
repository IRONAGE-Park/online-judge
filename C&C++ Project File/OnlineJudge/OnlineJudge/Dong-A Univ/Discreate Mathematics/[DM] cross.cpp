#include<iostream>
#include<fstream>
#include<vector>
#define MAX 10000

using namespace std;

int main() {
	ifstream inp("cross.inp");
	ofstream out("cross.out");
	int testcase;
	inp >> testcase;
	vector<int> lineU, lineD;
	lineU.resize(MAX), lineD.resize(MAX);
	for(int i = 1; i <= testcase; i++) {
		int N, num;
		inp >> N;
		for (int i = 0; i < N; i++) {
			inp >> num;
			lineU[num - 1] = i;
		}
		for (int i = 0; i < N; i++) {
			inp >> num;
			lineD[num - 1] = i;
		}
		int cross = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (i != j) {
					if (lineU[i] < lineU[j] && lineD[i] > lineD[j]) cross++;
					else if (lineU[i] > lineU[j] && lineD[i] < lineD[j]) cross++;
				}
			}
		}
		out << "Case " << i << ": " << cross << '\n';
	}
	inp.close();
	out.close();
	return 0;
}