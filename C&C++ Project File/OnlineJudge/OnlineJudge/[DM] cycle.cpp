#include<fstream>
#include<vector>
#include<queue>
#define ZERO
#define ODD 1
#define EVEN 2

using namespace std;

ifstream inp;
ofstream out;

typedef struct {
	int state; // ZERO이면 방문하지 않음, ODD이면 홀수, EVEN이면 짝수
	vector<int> near; // 인접 정점
}Vertex;
// 각 정점의 정보 구조체

bool CheckByBFS(vector< Vertex > &graph) {
	/* BFS를 기반으로 홀수 사이클 탐색 */
	graph[0].state = ODD; // 0번 정점을 기준으로 시작, 0번 정점은 홀수
	queue<int> queue; /// BFS를 위한 queue 선언
	queue.push(0);
	while (!queue.empty()) {
		int now = queue.front(), vCnt = graph[now].near.size(); // 큐에서 다음 탐색할 정점을 빼내고, 그 정점의 인접 정점 갯수 가져옴
		for (int i = 0; i < vCnt; i++) { // 모든 인접 정점에 대해서
			int next = graph[now].near[i]; // 인접 정점의 번호 저장
			if (graph[next].state) { // 방문한 정점이면
				if (graph[now].state == graph[next].state)
					// 인접 정점과 현재 정점이 같은 상태로 표시 == 홀수 사이클 그래프
					return true;
			}
			else { // 방문하지 않은 정점이면
				if (graph[now].state == ODD) // 현재 정점이 홀수이면
					graph[next].state = EVEN; // 그 방문하지 않은 인접 정점은 짝수
				else graph[next].state = ODD; // 반대의 경우 인접 정점은 홀수
				queue.push(next);
			}
		}
		queue.pop();
	}
	// BFS에서 단 한 번도 걸러지지 않은 그래프 == 짝수 사이클 그래프
	return false;
}

int main() {
	inp.open("cycle.inp");
	out.open("cycle.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int vertex, edge; // 정점 갯수와 간선 갯수
		inp >> vertex >> edge;
		Vertex component; /// 초기화를 위한 임시 변수 선언
		component.state = 0; /// 일단 정점에 방문하지 않았다고 표시
		component.near.reserve(vertex); /// 인접 정점을 넣을 공간 할당
		vector< Vertex > graph(vertex, component); /// 그래프 선언
		while (edge--) {
			int s, v;
			inp >> s >> v;
			graph[s].near.push_back(v);
			graph[v].near.push_back(s);
			/* 무방향 그래프이므로 양 방향에 인접 정점 추가 */
		}
		/* Input Data */
		if (CheckByBFS(graph)) out << "O\n";
		else out << "X\n";
		/* Output Data */
		graph.clear();
		/* Initialize */
	}
	inp.close();
	out.close();
	return 0;
}