#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct { int vertex; vector<int> edge; }Node; // 노드 구조체 선언

int N, M; // N = 최종 구성의 캡슐 수, M = 통로의 수
vector<Node> Graph; vector<Node *> E_Graph;

bool compare(Node *a, Node *b) { // 차수를 오름차순으로 정렬하기 위한 함수
	return a->edge.size() < b->edge.size();
}
void AllocVertex() { // 간선 정보 정렬 시킬 List 할당
	for (int i = 0; i < Graph.size(); i++) { Graph[i].vertex = i;  E_Graph[i] = &Graph[i]; }
}

void Delete(vector<int> *edge, int vertex) { // 간선 정보를 삭제하는 함수
	for (int i = 0; i < edge->size(); i++)
		if (edge->at(i) == vertex) 
			edge->erase(edge->begin() + i);
}

bool Search(vector<int> edge, int vertex) { // vertex와 연결되어 있는지 확인
	for (int i = 0; i < edge.size(); i++) 
		if (edge[i] == vertex) 
			return true;
	return false;
}

void Calculate(vector<Node *> Temp, int *cnt) { // 확인해야할 정보 확인
	if (Temp.size() != 0) {
		vector<Node *> temp;
		for (int i = 0; i < Temp.size(); i++) {
			if (Temp[i]->edge.size() == 2) {
				if (Search(Graph[Temp[i]->edge[0]].edge, Temp[i]->edge[1]) && Search(Graph[Temp[i]->edge[1]].edge, Temp[i]->edge[0])) { // 지울 수 있는 노드이면,
					Delete(&Graph[Temp[i]->edge[0]].edge, Temp[i]->vertex); Delete(&Graph[Temp[i]->edge[1]].edge, Temp[i]->vertex);
					temp.push_back(&Graph[Temp[i]->edge[0]]); temp.push_back(&Graph[Temp[i]->edge[1]]); // 변화가 있는 정점 저장
					Temp[i]->edge.clear(); // 삭제하는 정점
					*cnt = *cnt - 1; // 연산 횟수 추가
				}
			}
		}
		Calculate(temp, cnt); // 갱신된 정점 재 확인
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
		/* 그래프 선언 후 복사 리스트 할당 */
		for (int i = 0; i < M; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			Graph[v1 - 1].edge.push_back(v2 - 1); Graph[v2 - 1].edge.push_back(v1 - 1);
		}
		AllocVertex();
		/* INPUT DATA */
		sort(E_Graph.begin(), E_Graph.end(), compare); // 차수 순으로 정렬
		cout << "Case #" << T << '\n' << Solution() << '\n';
		Graph.clear(); E_Graph.clear();
	}
	return 0;
}