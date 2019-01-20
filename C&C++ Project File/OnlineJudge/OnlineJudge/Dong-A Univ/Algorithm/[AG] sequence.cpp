#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> SetPos(vector<int> list, vector<int> seq) {
	vector<int> sortList(list.size());
	for (int i = seq.size() - 1; i >= 0; i--) {
		sortList[i] = list[seq[i]];
		list.erase(list.begin() + seq[i]);
	}
	return sortList;
}

int main() {
	ifstream inp("sequence.inp");
	ofstream out("sequence.out");
	vector<int> list, seq, sortList;
	int N;
	inp >> N;
	list.resize(N), seq.resize(N);
	for (int i = 0; i < N; i++)	inp >> list[i];
	for (int i = 0; i < N; i++) inp >> seq[i];
	/* INPUT DATA */
	sort(list.begin(), list.end());
	sortList = SetPos(list, seq);
	for (int i = 0; i < sortList.size(); i++)
		out << sortList[i] << '\n';
	inp.close();
	out.close();
	return 0;
}