#include<iostream>
#include<fstream>

std::ifstream inp;
std::ofstream out;

typedef struct Input { // input data ���� <- ���� ����
	int u;
	int v;
	int w;
	int num;
}Input;

typedef struct Node { // find��
	int vertex;
	int height;
	struct Node *parent;
}Node;

typedef struct Graph { // �׷��� ����ü
	struct Graph *next;
	struct Input data;
}Graph;

int vertex, edge;
Input data[100010], temp[100010];
Graph *graph[10010], *Last[10010];
Node *List[10010];

void Scan() { // input.
	inp >> vertex >> edge;
	for (int i = 0; i < vertex; i++) {
		List[i] = new Node, List[i]->vertex = i, List[i]->parent = NULL, List[i]->height = 0;
		graph[i] = new Graph, graph[i]->next = NULL;
		Last[i] = new Graph, Last[i]->next = graph[i];
	}
	for (int i = 0; i < edge; i++) {
		inp >> data[i].u >> data[i].v >> data[i].w;
		data[i].num = i;
		Graph *temp1 = Last[data[i].u]->next, *temp2 = Last[data[i].v]->next;
		temp1->next = new Graph;
		temp1->next->next = NULL, temp1->next->data = data[i];
		Last[data[i].u]->next = temp1->next;
		temp2->next = new Graph;
		temp2->next->next = NULL, temp2->next->data = data[i];
		Last[data[i].v]->next = temp2->next;
	}
}
void Merge(int left, int mid, int right) { // �պ�
	int i, j, k, m;
	i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (data[i].w > data[j].w) temp[k] = data[j], j++;
		else temp[k] = data[i], i++;
		k++;
	}
	if (i > mid) for (m = j; m <= right; m++) temp[k] = data[m], k++;
	else for (m = i; m <= mid; m++) temp[k] = data[m], k++;
	for (m = left; m <= right; m++) data[m] = temp[m];
}
void Merge_Sort(int left, int right) { // kruskal���� ����� ���� ����
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		Merge_Sort(left, mid);
		Merge_Sort(mid + 1, right);
		Merge(left, mid, right);
	}
}
int Find(Node *node) { // find ����
	Node *temp = node;
	int h = 0;
	while (temp->parent != NULL) {
		temp = temp->parent;
		h++;
	}
	temp->height = h;
	return temp->vertex;
}
void Kruskal() {
	Merge_Sort(0, edge - 1); // ��� edge�� ������������ ����
	int edge_num = 0, seq = 0, sum = 0; // num = ���Ե� ���� ����
	int select[10010];
	while (edge_num < vertex - 1 && edge - 1 > seq) {
		if (List[data[seq].u]->parent == NULL && List[data[seq].v]->parent == NULL) { // �� �� �θ� ��尡 ������
			List[data[seq].v]->parent = List[data[seq].u];
			select[edge_num] = data[seq].num;
			sum += data[seq].w;
			edge_num++;
		} // �� ���� ��带 ���� -> edge �߰�
		else { // �θ� ��尡 �����ϸ�
			int find_pointer_v = Find(List[data[seq].v]); // �� �ʿ��� ���� ����
			int find_pointer_u = Find(List[data[seq].u]);
			if (find_pointer_u != find_pointer_v) { // �� ��尡 ���� �θ� ����Ű���� Ȯ��
				if (List[find_pointer_u]->height < List[find_pointer_v]->height) List[find_pointer_u]->parent = List[data[seq].v];
				else List[find_pointer_v]->parent = List[data[seq].u];
				select[edge_num] = data[seq].num;
				sum += data[seq].w;
				edge_num++;
			} // �ٸ� �θ� ����ų ��� �� �� �θ� ��带 �ٸ� ���� �ڽ����� ���� -> edge �߰�
		}
		seq++;
	}
	out << "Tree edges by Kruskal algorithm: " << sum << '\n';
	for (int i = 0; i < edge_num; i++) out << select[i] << '\n';
}

Input heap[200020];
int size = 0;
void Exchange(int index1, int index2) { // ��ȯ
	Input temp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = temp;
}
void Insert(Input edge) { // ����
	size++;
	heap[size] = edge;
	int search = size;
	while (search != 1) { // Insertion �˰���
		if (heap[search].w < heap[(search / 2)].w) Exchange(search, search / 2);
		else if (heap[search].w == heap[(search / 2)].w) {
			if (heap[search].num < heap[(search / 2)].num) Exchange(search, search / 2);
		}
		else break;
		search /= 2;
	}
}
Input Dequeue() { // ����
	Input temp = heap[1];
	heap[1] = heap[size];
	heap[size].num = -1, heap[size].u = -1, heap[size].v = -1, heap[size].w = 99999, size--;
	int search = 1;
	while ((search * 2) <= size) { // adjust �˰���
		if (heap[search * 2].w > heap[(search * 2) + 1].w) {
			if (heap[search].w > heap[(search * 2) + 1].w) {
				Exchange(search, (search * 2) + 1);
				search = (search * 2) + 1;
			}
			else break;
		}
		else if (heap[search * 2].w == heap[(search * 2) + 1].w && heap[search * 2].w < heap[search].w) {
			if (heap[search * 2].num < heap[(search * 2) + 1].num) {
				Exchange(search, search * 2);
				search *= 2;
			}
			else {
				Exchange(search, (search * 2) + 1);
				search = (search * 2) + 1;
			}
		}
		else {
			if (heap[search].w > heap[(search * 2)].w) {
				Exchange(search, (search * 2));
				search *= 2;
			}
			else break;
		}
	}
	return temp;
}
void Prim(int S) {
	int edge_num = 0, sum = 0;
	int select[10010], visit[10010] = { 0 };
	Graph *temp = graph[S]->next;
	visit[S] = 1;
	while (temp != NULL) Insert(temp->data), temp = temp->next;
	while (edge_num < vertex - 1 && size > 0) {
		Input choose = Dequeue();
		if (visit[choose.u] == 1 && visit[choose.v] == 1) continue; // �� �� �湮�� ����� ���
		if (visit[choose.v] != 1) { // v�� �湮 �� ������
			temp = graph[choose.v]->next;
			visit[choose.v] = 1;
			while (temp != NULL) Insert(temp->data), temp = temp->next;
		}
		else { // u�� �湮 �� ������
			temp = graph[choose.u]->next;
			visit[choose.u] = 1;
			while (temp != NULL) Insert(temp->data), temp = temp->next;
		}
		select[edge_num] = choose.num;
		sum += choose.w;
		edge_num++;
	}
	out << "Tree edges by Prim algorithm with starting vertex " << S << ": " << sum << '\n';
	for (int i = 0; i < edge_num; i++) out << select[i] << '\n';
}

int main() {
	inp.open("mst.inp");
	out.open("mst.out");
	Scan(); // input.
	Kruskal(); // Kruskal.
	Input init;
	init.num = 0, init.u = 0, init.v = 0, init.w = 0;
	Prim(0), size = 0;
	for (int i = 0; i <= edge * 2; i++) heap[i] = init;
	Prim(vertex / 2), size = 0;
	for (int i = 0; i <= edge * 2; i++) heap[i] = init;
	Prim(vertex - 1); // Prim.
	inp.close();
	out.close();
	return 0;
}