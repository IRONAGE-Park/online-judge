#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> PAIR; // pair�� ȿ�������� ����ϱ� ���� ����
typedef struct {
	bool visit; // �湮 ����
	vector<PAIR> adj; // ���� ��� ����Ʈ
					  // ���� int�� ���� ����� ��ȣ, ���� int�� �� ��� ������ ����ġ
}Vertex; // �� ������ ���� �����ϴ� ����ü ����

void Prim(vector<Vertex> &graph, vector<PAIR> &result, int s) {
	/* Prim �˰��� ���� */
	/* ���� ����Ʈ�� ������ �׷����� ���� ���� */
	priority_queue< PAIR, vector<PAIR>, greater<PAIR> > pq; // ����ġ�� ���� �ּ� �켱���� ť
	int cnt = 0, total = 0; // MST�� ��� ������ ����ġ�� ��
	pq.push(make_pair(0, s)); // �켱���� ť�� �⺻ ������ ���� ��带 �־� ��
	while (!pq.empty()) {
		/* �켱���� ť�� ���� ���°� �� ������ */
		PAIR next = pq.top();
		pq.pop();
		// �켱���� ť���� ���� ������ �ϳ� ����
		if (!graph[next.second].visit) {
			/* ���� �湮���� ���� ����� ��� */
			graph[next.second].visit = true; // �湮�ߴٰ� ǥ��
			cnt++; // MST ���� ��� ���� ����
			total += next.first; // MST ���� ����ġ�� �� ����
			for (int i = 0; i < graph[next.second].adj.size(); i++) {
				// ������ ���� ����� ��� ���� ��忡 ���ؼ�
				PAIR to = graph[next.second].adj[i]; // �� ���� ��带 ����
				if (!graph[to.first].visit)
					/* ������ ���� ����� ���� ��尡 �湮���� ���� ����� ��� */
					pq.push(make_pair(to.second, to.first));
			}
		}
		// �湮�� ����� ��� �� �ʿ� ����
	}
	result.push_back(make_pair(cnt, total));
	// Prim Algorithm�� ����� ����
}

int main() {
	ifstream inp("mst.inp");
	ofstream out("mst.out");
	int N, M;
	inp >> N >> M;
	Vertex comp; // resize�� ���� �ӽ� ����
	comp.adj.reserve(N);
	comp.visit = false;
	vector<Vertex> graph(N, comp);
	/* �׷��� ����� �ʱ�ȭ */
	while (M--) {
		int u, v, w;
		inp >> u >> v >> w;
		graph[u].adj.push_back(make_pair(v, w));
		graph[v].adj.push_back(make_pair(u, w));
		// �׷��� ����
	}
	/* INPUT */
	vector<PAIR> result; // ����� ������ �迭
						 // first = MST ����� ����, second = MST ����ġ�� ��
	result.reserve(N); // ����� ������ ���� �̸� �Ҵ�
	for (int i = 0; i < N; i++) {
		if (!graph[i].visit)
			// �湮���� ���� ���(������ ���� �׷���)�� ���ؼ� Prim �˰��� ����
			Prim(graph, result, i);
	}
	sort(result.begin(), result.end()); // MST ��� ���� ������ ����
	for (int i = 0; i < result.size(); i++)
		out << result.at(i).first << ' ' << result.at(i).second << '\n';
	/* OUTPUT */
	inp.close();
	out.close();
	return 0;
}
