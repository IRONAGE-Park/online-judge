#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

bool CheckGoodMatrix(vector< vector<int> > matrix) {
	bool result = true;
	for (int i = 0; i < matrix.size() && result; i++) {
		for (int j = 0; j < matrix[i].size() && result; j++) {
			if (matrix[i][j] != 1) {
				bool check = true;
				for (int s = 0; s < matrix.size() && check; s++) {
					for (int t = 0; t < matrix[i].size() && check; t++) {
						if (matrix[i][s] + matrix[t][j] == matrix[i][j])
							check = false;
					}
				}
				if (check) result = false;
			}
		}
	}
	return result;
}

int main() {
	ifstream inp("matrix.inp");
	ofstream out("matrix.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int N;
		inp >> N;
		vector< vector<int> > matrix;
		matrix.resize(N);
		for (int i = 0; i < N; i++) {
			matrix[i].resize(N);
			for (int j = 0; j < N; j++) inp >> matrix[i][j];
		}
		out << CheckGoodMatrix(matrix) << '\n';
		matrix.clear();
	}
	inp.close();
	out.close();
	return 0;
}