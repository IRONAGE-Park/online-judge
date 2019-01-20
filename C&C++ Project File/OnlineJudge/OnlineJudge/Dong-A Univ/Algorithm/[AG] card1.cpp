#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#define Min(a,b) (a > b ? b : a)

using namespace std;

int cal(vector< vector<int> > &Alice, vector< vector<int> > &Robot) {
	for (int j = 1; j < Alice.size(); j++) {
		for (int i = 0; i + j < Alice[i].size(); i++) {
			Robot[i][j + i] = Min(Alice[i][j + i - 1], Alice[i + 1][j + i]);
			Alice[i][j + i] = (Alice[i][j + i - 1] + Robot[i][j + i - 1] + Alice[j + i][j + i]) - Robot[i][j + i];
		}
	}
	return Alice[0][Alice[0].size() - 1];
}

int main() {
	ifstream inp("card.inp");
	ofstream out("card.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int num;
		inp >> num;
		vector<int> data(num);
		vector< vector<int> > Alice(num, data), Robot(num, data);
		for (int i = 0; i < num; i++) inp >> Alice[i][i];
		out << cal(Alice, Robot) << '\n';
	}
	inp.close();
	out.close();
	return 0;
}