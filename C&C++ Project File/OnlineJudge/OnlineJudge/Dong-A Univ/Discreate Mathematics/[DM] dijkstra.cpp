#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#define MAX 10000
#define INF 0x7FFFFFFF

using namespace std;

ifstream inp;
ofstream out;

typedef struct {
	int v, w; // 대상 정점과 그 정점까지의 가중치
	int eNum; // 간선의 들어온 순서
}Node;
// 그래프의 정점 구조체

typedef struct {
	int distance; // 최단 거리
	int parent; // 최단 경로를 저장하기 위해 바로 전에 지나친 정점 저장
	int eNum; // 형식에 맞게 경로 출력하기 위해 사용된 간선의 입력 순서 저장
	bool visit; // 정점 방문 여부
}V_info;
// 각 정점의 정보를 저장하는 구조체

void Dijkstra(vector< vector<Node> > &graph, vector<V_info> &disGroup) { // 최단 거리 && 경로 구하는 함수
	V_info component; // 정점 정보 구조체 선언
	component.distance = INF; // 확인 되지 않은 거리는 INF
	component.visit = false; // 방문하지 않은 상태
	component.parent = -1; // 이 전에 아무 정점도 방문하지 않음
	component.eNum = -1; // 어떤 간선도 거치지 않음
	/* 정점 정보 배열의 내부 값들을 INF로 초기화 시키기 위해 만든 임시 변수 */
	disGroup.resize(graph.size(), component); /// 정점 정보 배열 선언 && 초기화
	disGroup[0].distance = 0;
	/* 0번 정점까지의 거리와 경로는 0(자기 자신) */
	queue<int> queue; /// queue 선언
	queue.push(0); ///
	/* queue를 이용하여 BFS탐색, 우선 시작 정점인 0번 정점 삽입 */
	while (!queue.empty()) { ///
		int now = queue.front(); ///
		disGroup[now].visit = true;
		for (int i = 0; i < graph[now].size(); i++) {
			/* 방문 정점의 모든 인접 정점을 고려 */
			Node near = graph[now][i]; // 인접 정점 번호와 가중치 저장
			int alt = disGroup[now].distance + near.w; // 새로 계산한 그 노드까지의 거리
			if (disGroup[near.v].distance > alt) {
				/* 인접 정점까지의 원래 알려진 거리보다 새로 알게된 거리가 더 짧다면 갱신 */
				disGroup[near.v].distance = alt; // 거리 갱신
				disGroup[near.v].parent = now; // 경로 갱신
				disGroup[near.v].eNum = near.eNum; // 사용된 간선 갱신
				queue.push(near.v); /// 인접 정점을 우선 큐에 삽입
			}
			else if (disGroup[near.v].distance == alt) {
				if (disGroup[near.v].eNum < near.eNum) {
					/* 인접 정점까지의 원래 알려진 거리보다 새로 알게된 거리가 같더라도 새로 사용된 간선의 입력 순서가 더 높다면 갱신 */
					disGroup[near.v].parent = now; // 경로 갱신
					disGroup[near.v].eNum = near.eNum; // 사용된 간선 갱신
				}
			}
		}
		queue.pop(); /// 방문한 정점은 큐에서 뺌
	}
}

void CreatePath(vector<int> &path, vector<V_info> &result, int destination) { // 각 정점에 이전 노드의 기록을 이용하여 경로 만듬
	path.push_back(destination); /// 최종 목적지 정점 번호 삽입
	int now = result[destination].parent; // 최종 목적지에 도달하기 전 정점 번호 저장
	while (now != -1) { // 최종 목적지에 도달하기 전 정점 번호가 -1이 아닐 때까지 => 0번 정점에 도달할 때까지
		path.push_back(now); /// 그 정점 번호를 삽입하고
		now = result[now].parent; // 그 정점의 이전 정점 저장
	}
}

void Print(vector<V_info> &result) { // 정점 출력 함수
	for (int i = 1; i < result.size(); i++) {
		if (result[i].visit != 0) { // 방문한 적이 있을 경우(적어도 경로가 존재)
			vector<int> path; // 경로 저장할 배열 선언
			path.reserve(MAX); /// 미리 공간 할당
			CreatePath(path, result, i); // 경로를 역순으로 저장함
			for (int i = path.size() - 1; i >= 0; i--)
				out << 'V' << path[i] << ' ';
			out << '(' << result[i].distance << ")\n";
		}
		else // 방문한 적이 없으면(경로가 존재하지 않음 == 거리 -1)
			out << "V0 V" << i << " (-1)\n";
	}
}

int main() {
    inp.open("input.txt");
    out.open("output.txt");
//	inp.open("dijkstra.inp");
//	out.open("dijkstra.out");
	int vertex, edge; // 정점과 간선의 수
	inp >> vertex >> edge;
	vector< vector<Node> > graph(vertex); /// 그래프 선언
	vector<V_info> result; /// 결과를 저장할 배열 선언
	for (int i = 0; i < edge; i++) {
		int s; // 출발 정점
		Node node; // graph에 인접행렬 형태로 삽입할 정점 선언(도착 정점)
		inp >> s >> node.v >> node.w;
		node.eNum = i; // 간선의 입력 순서
		graph[s].push_back(node); /// 정점 삽입
	}
	/* Input Data */
	Dijkstra(graph, result); // 최단 거리 && 경로 계산 후 결과 저장
	Print(result);
	/* Output Data*/
	inp.close();
	out.close();
	return 0;
}