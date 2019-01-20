#include<iostream>
#include<vector>
#define INF 0xFFFFFFF

using namespace std;

vector< vector<int> > Graph;
vector<int> Line;

int Min = INF;
int N, M; // ������ ��, ������ ��
int abs(int x) {
	if (x < 0) return x * -1;
	return x;
}
bool Exist(vector<int> list, int vertex) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == vertex) return true;
	}
	return false;
}
int Search_Position(vector<int> list, int vertex) {
	for (int i = 0; i < list.size(); i++)
		if (list[i] == vertex) return i;
}

int Calculate(vector<int> list) { // ��� ���� ������ �Ÿ� ���
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int pos = Search_Position(list, i);
		for (int j = 0; j < Graph[i].size(); j++) {
			int t_pos = Search_Position(list, Graph[i][j]);
			sum += abs(pos - t_pos);
		}
	}
	return sum / 2;
}

void Sol(vector<int> list) {
	if (list.size() == N) { // ���� ä������
		int distance = Calculate(list);
		if (distance < Min) {
			Min = distance;
			Line = list;
		}
	}
	else { // ��ġ�� �߰��ؾ��� ���
		for (int i = 0; i < N; i++) {
			if (!Exist(list, i)) {
				list.push_back(i);
				Sol(list);
				list.pop_back();
			}
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for (int T = 1; T <= testcase; T++) {
		cin >> N >> M;
		Graph.resize(N); Line.resize(N);
		for (int i = 0; i < M; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			Graph[v1].push_back(v2); Graph[v2].push_back(v1);
		}
		for (int i = 0; i < N; i++) {
			vector<int> list(1, i);
			Sol(list);
		}
		cout << "Case #" << T << '\n' << Min << '\n';
		for (int i = 0; i < Line.size(); i++) cout << Line[i] << ' ';
		cout << '\n';
		Graph.clear(); Line.clear(); Min = INF;
	}
	return 0;
}