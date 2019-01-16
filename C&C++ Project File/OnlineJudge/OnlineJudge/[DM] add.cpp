#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


typedef long long int lint;
typedef priority_queue< lint, vector<lint>, greater<lint> > PQ;

lint CalculateCost(PQ &queue) {
	lint cost = 0, result = 0;
	while (queue.size() != 1) {
		result += queue.top();
		queue.pop();
		result += queue.top();
		queue.pop();
		queue.push(result);
		cost += result;
		result = 0;
	}
	return cost;
}

int main() {
	ifstream inp("add.inp");
	ofstream out("add.out");
	//    ifstream inp("input.txt");
	//    ofstream out("output.txt");
	while (true) {
		int N;
		inp >> N;
		if (!N) break;
		PQ queue;
		for (int i = 0; i < N; i++) {
			int num;
			inp >> num;
			queue.push(num);
		}
		out << CalculateCost(queue) << '\n';
	}
	inp.close();
	out.close();
	return 0;
}