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
	int v, w; // ��� ������ �� ���������� ����ġ
	int eNum; // ������ ���� ����
}Node;
// �׷����� ���� ����ü

typedef struct {
	int distance; // �ִ� �Ÿ�
	int parent; // �ִ� ��θ� �����ϱ� ���� �ٷ� ���� ����ģ ���� ����
	int eNum; // ���Ŀ� �°� ��� ����ϱ� ���� ���� ������ �Է� ���� ����
	bool visit; // ���� �湮 ����
}V_info;
// �� ������ ������ �����ϴ� ����ü

void Dijkstra(vector< vector<Node> > &graph, vector<V_info> &disGroup) { // �ִ� �Ÿ� && ��� ���ϴ� �Լ�
	V_info component; // ���� ���� ����ü ����
	component.distance = INF; // Ȯ�� ���� ���� �Ÿ��� INF
	component.visit = false; // �湮���� ���� ����
	component.parent = -1; // �� ���� �ƹ� ������ �湮���� ����
	component.eNum = -1; // � ������ ��ġ�� ����
	/* ���� ���� �迭�� ���� ������ INF�� �ʱ�ȭ ��Ű�� ���� ���� �ӽ� ���� */
	disGroup.resize(graph.size(), component); /// ���� ���� �迭 ���� && �ʱ�ȭ
	disGroup[0].distance = 0;
	/* 0�� ���������� �Ÿ��� ��δ� 0(�ڱ� �ڽ�) */
	queue<int> queue; /// queue ����
	queue.push(0); ///
	/* queue�� �̿��Ͽ� BFSŽ��, �켱 ���� ������ 0�� ���� ���� */
	while (!queue.empty()) { ///
		int now = queue.front(); ///
		disGroup[now].visit = true;
		for (int i = 0; i < graph[now].size(); i++) {
			/* �湮 ������ ��� ���� ������ ��� */
			Node near = graph[now][i]; // ���� ���� ��ȣ�� ����ġ ����
			int alt = disGroup[now].distance + near.w; // ���� ����� �� �������� �Ÿ�
			if (disGroup[near.v].distance > alt) {
				/* ���� ���������� ���� �˷��� �Ÿ����� ���� �˰Ե� �Ÿ��� �� ª�ٸ� ���� */
				disGroup[near.v].distance = alt; // �Ÿ� ����
				disGroup[near.v].parent = now; // ��� ����
				disGroup[near.v].eNum = near.eNum; // ���� ���� ����
				queue.push(near.v); /// ���� ������ �켱 ť�� ����
			}
			else if (disGroup[near.v].distance == alt) {
				if (disGroup[near.v].eNum < near.eNum) {
					/* ���� ���������� ���� �˷��� �Ÿ����� ���� �˰Ե� �Ÿ��� ������ ���� ���� ������ �Է� ������ �� ���ٸ� ���� */
					disGroup[near.v].parent = now; // ��� ����
					disGroup[near.v].eNum = near.eNum; // ���� ���� ����
				}
			}
		}
		queue.pop(); /// �湮�� ������ ť���� ��
	}
}

void CreatePath(vector<int> &path, vector<V_info> &result, int destination) { // �� ������ ���� ����� ����� �̿��Ͽ� ��� ����
	path.push_back(destination); /// ���� ������ ���� ��ȣ ����
	int now = result[destination].parent; // ���� �������� �����ϱ� �� ���� ��ȣ ����
	while (now != -1) { // ���� �������� �����ϱ� �� ���� ��ȣ�� -1�� �ƴ� ������ => 0�� ������ ������ ������
		path.push_back(now); /// �� ���� ��ȣ�� �����ϰ�
		now = result[now].parent; // �� ������ ���� ���� ����
	}
}

void Print(vector<V_info> &result) { // ���� ��� �Լ�
	for (int i = 1; i < result.size(); i++) {
		if (result[i].visit != 0) { // �湮�� ���� ���� ���(��� ��ΰ� ����)
			vector<int> path; // ��� ������ �迭 ����
			path.reserve(MAX); /// �̸� ���� �Ҵ�
			CreatePath(path, result, i); // ��θ� �������� ������
			for (int i = path.size() - 1; i >= 0; i--)
				out << 'V' << path[i] << ' ';
			out << '(' << result[i].distance << ")\n";
		}
		else // �湮�� ���� ������(��ΰ� �������� ���� == �Ÿ� -1)
			out << "V0 V" << i << " (-1)\n";
	}
}

int main() {
    inp.open("input.txt");
    out.open("output.txt");
//	inp.open("dijkstra.inp");
//	out.open("dijkstra.out");
	int vertex, edge; // ������ ������ ��
	inp >> vertex >> edge;
	vector< vector<Node> > graph(vertex); /// �׷��� ����
	vector<V_info> result; /// ����� ������ �迭 ����
	for (int i = 0; i < edge; i++) {
		int s; // ��� ����
		Node node; // graph�� ������� ���·� ������ ���� ����(���� ����)
		inp >> s >> node.v >> node.w;
		node.eNum = i; // ������ �Է� ����
		graph[s].push_back(node); /// ���� ����
	}
	/* Input Data */
	Dijkstra(graph, result); // �ִ� �Ÿ� && ��� ��� �� ��� ����
	Print(result);
	/* Output Data*/
	inp.close();
	out.close();
	return 0;
}