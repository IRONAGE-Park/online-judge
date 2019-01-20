#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> PAIR; // pair를 효과적으로 사용하기 위해 정의
typedef struct {
	bool visit; // 방문 정보
	vector<PAIR> adj; // 인접 노드 리스트
					  // 앞의 int는 도착 노드의 번호, 뒤의 int는 그 노드 까지의 가중치
}Vertex; // 각 정점의 정보 저장하는 구조체 선언

void Prim(vector<Vertex> &graph, vector<PAIR> &result, int s) {
	/* Prim 알고리즘 구현 */
	/* 인접 리스트로 구현한 그래프와 시작 정점 */
	priority_queue< PAIR, vector<PAIR>, greater<PAIR> > pq; // 가중치가 기준 최소 우선순위 큐
	int cnt = 0, total = 0; // MST의 노드 갯수와 가중치의 합
	pq.push(make_pair(0, s)); // 우선순위 큐에 기본 값으로 시작 노드를 넣어 줌
	while (!pq.empty()) {
		/* 우선순위 큐가 공백 상태가 될 때까지 */
		PAIR next = pq.top();
		pq.pop();
		// 우선순위 큐에서 간선 정보를 하나 빼냄
		if (!graph[next.second].visit) {
			/* 만약 방문하지 않은 노드일 경우 */
			graph[next.second].visit = true; // 방문했다고 표시
			cnt++; // MST 구성 노드 갯수 증가
			total += next.first; // MST 구성 가중치의 합 증가
			for (int i = 0; i < graph[next.second].adj.size(); i++) {
				// 연결한 도착 노드의 모든 인접 노드에 대해서
				PAIR to = graph[next.second].adj[i]; // 한 인접 노드를 저장
				if (!graph[to.first].visit)
					/* 연결한 도착 노드의 인접 노드가 방문하지 않은 노드일 경우 */
					pq.push(make_pair(to.second, to.first));
			}
		}
		// 방문한 노드일 경우 볼 필요 없음
	}
	result.push_back(make_pair(cnt, total));
	// Prim Algorithm의 결과를 저장
}

int main() {
	ifstream inp("mst.inp");
	ofstream out("mst.out");
	int N, M;
	inp >> N >> M;
	Vertex comp; // resize를 위한 임시 변수
	comp.adj.reserve(N);
	comp.visit = false;
	vector<Vertex> graph(N, comp);
	/* 그래프 선언과 초기화 */
	while (M--) {
		int u, v, w;
		inp >> u >> v >> w;
		graph[u].adj.push_back(make_pair(v, w));
		graph[v].adj.push_back(make_pair(u, w));
		// 그래프 제작
	}
	/* INPUT */
	vector<PAIR> result; // 결과를 저장할 배열
						 // first = MST 노드의 갯수, second = MST 가중치의 합
	result.reserve(N); // 결과를 저장할 공간 미리 할당
	for (int i = 0; i < N; i++) {
		if (!graph[i].visit)
			// 방문하지 않은 노드(독립된 연결 그래프)에 대해서 Prim 알고리즘 수행
			Prim(graph, result, i);
	}
	sort(result.begin(), result.end()); // MST 노드 갯수 순으로 정렬
	for (int i = 0; i < result.size(); i++)
		out << result.at(i).first << ' ' << result.at(i).second << '\n';
	/* OUTPUT */
	inp.close();
	out.close();
	return 0;
}
