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
	int state; // ZERO�̸� �湮���� ����, ODD�̸� Ȧ��, EVEN�̸� ¦��
	vector<int> near; // ���� ����
}Vertex;
// �� ������ ���� ����ü

bool CheckByBFS(vector< Vertex > &graph) {
	/* BFS�� ������� Ȧ�� ����Ŭ Ž�� */
	graph[0].state = ODD; // 0�� ������ �������� ����, 0�� ������ Ȧ��
	queue<int> queue; /// BFS�� ���� queue ����
	queue.push(0);
	while (!queue.empty()) {
		int now = queue.front(), vCnt = graph[now].near.size(); // ť���� ���� Ž���� ������ ������, �� ������ ���� ���� ���� ������
		for (int i = 0; i < vCnt; i++) { // ��� ���� ������ ���ؼ�
			int next = graph[now].near[i]; // ���� ������ ��ȣ ����
			if (graph[next].state) { // �湮�� �����̸�
				if (graph[now].state == graph[next].state)
					// ���� ������ ���� ������ ���� ���·� ǥ�� == Ȧ�� ����Ŭ �׷���
					return true;
			}
			else { // �湮���� ���� �����̸�
				if (graph[now].state == ODD) // ���� ������ Ȧ���̸�
					graph[next].state = EVEN; // �� �湮���� ���� ���� ������ ¦��
				else graph[next].state = ODD; // �ݴ��� ��� ���� ������ Ȧ��
				queue.push(next);
			}
		}
		queue.pop();
	}
	// BFS���� �� �� ���� �ɷ����� ���� �׷��� == ¦�� ����Ŭ �׷���
	return false;
}

int main() {
	inp.open("cycle.inp");
	out.open("cycle.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int vertex, edge; // ���� ������ ���� ����
		inp >> vertex >> edge;
		Vertex component; /// �ʱ�ȭ�� ���� �ӽ� ���� ����
		component.state = 0; /// �ϴ� ������ �湮���� �ʾҴٰ� ǥ��
		component.near.reserve(vertex); /// ���� ������ ���� ���� �Ҵ�
		vector< Vertex > graph(vertex, component); /// �׷��� ����
		while (edge--) {
			int s, v;
			inp >> s >> v;
			graph[s].near.push_back(v);
			graph[v].near.push_back(s);
			/* ������ �׷����̹Ƿ� �� ���⿡ ���� ���� �߰� */
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