#include<iostream>
#include<fstream>
#include<vector>
#define MAX 103

using namespace std;

vector< vector< vector<int> > > bucket;

void Solution() {
    bucket.resize(MAX);
    for(int i = 0; i < MAX; i++){
        bucket[i].resize(MAX);
        for(int j = 0; j < MAX; j++){
            bucket[i][j].resize(MAX);
        }
    }
	for (int i = 3; i < MAX; i++) {
		for (int j = 3; j < MAX; j++) {
			for (int k = 3; k < MAX; k++) {
				if (i == 3 && j == 3 && k == 3) bucket[i][j][k] = 0;
				else if (bucket[i - 1][j][k] == -1 || bucket[i][j - 1][k] == -1 || bucket[i][j][k - 1] == -1) {
					bucket[i][j][k] = 1;
				}
				else {
					if (bucket[i - 2][j][k] == -1 || bucket[i][j - 2][k] == -1 || bucket[i][j][k - 2] == -1) {
						bucket[i][j][k] = 1;
					}
					else {
						if (bucket[i - 3][j][k] == -1 || bucket[i][j - 3][k] == -1 || bucket[i][j][k - 3] == -1) {
							bucket[i][j][k] = 1;
						}
						else {
							bucket[i][j][k] = -1;
						}
					}
				}
			}
		}
	}
}

int main() {
    ifstream inp("coin.inp");
    ofstream out("coin.out");
	int testcase;
    inp >> testcase;
	int b[3];
	Solution();
	while (testcase--) {
        inp >> b[0] >> b[1] >> b[2];
        out << '(' << b[0] << ' ' << b[1] << ' ' << b[2] << ") : " << bucket[b[0] + 3][b[1] + 3][b[2] + 3] << '\n';
	}
    inp.close();
    out.close();
	return 0;
}
