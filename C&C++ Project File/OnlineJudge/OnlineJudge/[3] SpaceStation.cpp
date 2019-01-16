#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct { int vertex; vector<int> edge; }Node; // ��� ����ü ����

int N, M; // N = ���� ������ ĸ�� ��, M = ����� ��
vector<Node> Graph; vector<Node *> E_Graph;

bool compare(Node *a, Node *b) { // ������ ������������ �����ϱ� ���� �Լ�
	return a->edge.size() < b->edge.size();
}
void AllocVertex() { // ���� ���� ���� ��ų List �Ҵ�
	for (int i = 0; i < Graph.size(); i++) { Graph[i].vertex = i;  E_Graph[i] = &Graph[i]; }
}

void Delete(vector<int> *edge, int vertex) { // ���� ������ �����ϴ� �Լ�
	for (int i = 0; i < edge->size(); i++)
		if (edge->at(i) == vertex) 
			edge->erase(edge->begin() + i);
}

bool Search(vector<int> edge, int vertex) { // vertex�� ����Ǿ� �ִ��� Ȯ��
	for (int i = 0; i < edge.size(); i++) 
		if (edge[i] == vertex) 
			return true;
	return false;
}

void Calculate(vector<Node *> Temp, int *cnt) { // Ȯ���ؾ��� ���� Ȯ��
	if (Temp.size() != 0) {
		vector<Node *> temp;
		for (int i = 0; i < Temp.size(); i++) {
			if (Temp[i]->edge.size() == 2) {
				if (Search(Graph[Temp[i]->edge[0]].edge, Temp[i]->edge[1]) && Search(Graph[Temp[i]->edge[1]].edge, Temp[i]->edge[0])) { // ���� �� �ִ� ����̸�,
					Delete(&Graph[Temp[i]->edge[0]].edge, Temp[i]->vertex); Delete(&Graph[Temp[i]->edge[1]].edge, Temp[i]->vertex);
					temp.push_back(&Graph[Temp[i]->edge[0]]); temp.push_back(&Graph[Temp[i]->edge[1]]); // ��ȭ�� �ִ� ���� ����
					Temp[i]->edge.clear(); // �����ϴ� ����
					*cnt = *cnt - 1; // ���� Ƚ�� �߰�
				}
			}
		}
		Calculate(temp, cnt); // ���ŵ� ���� �� Ȯ��
	}
}

int Solution() {
	int cnt = Graph.size();
	Calculate(E_Graph, &cnt);
	return cnt;
}

int main() {
	int testcase;
	cin >> testcase;
	for (int T = 1; T <= testcase; T++) {
		cin >> N >> M;
		Graph.resize(N); E_Graph.resize(N);
		/* �׷��� ���� �� ���� ����Ʈ �Ҵ� */
		for (int i = 0; i < M; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			Graph[v1 - 1].edge.push_back(v2 - 1); Graph[v2 - 1].edge.push_back(v1 - 1);
		}
		AllocVertex();
		/* INPUT DATA */
		sort(E_Graph.begin(), E_Graph.end(), compare); // ���� ������ ����
		cout << "Case #" << T << '\n' << Solution() << '\n';
		Graph.clear(); E_Graph.clear();
	}
	return 0;
}