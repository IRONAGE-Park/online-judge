#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#define MAX 10000
#define INF 0x7FFFFFFF

typedef struct {
	int v, w; // ��� ������ �� ���������� ����ġ
	int eNum; // ������ ���� ����
}Node;
// �׷����� ���� ����ü

typedef struct {
	Node near[MAX]; // ���� ���
	int len; // ���� ��� ����
}Graph;
// �׷����� ���� ����ü

typedef struct {
	int distance; // �ִ� �Ÿ�
	int parent; // �ִ� ��θ� �����ϱ� ���� �ٷ� ���� ����ģ ���� ����
	int eNum; // ���Ŀ� �°� ��� ����ϱ� ���� ���� ������ �Է� ���� ����
	int visit; // ���� �湮 ����
}V_info;
// �� ������ ������ �����ϴ� ����ü

typedef struct {
	int list[MAX]; // ��� ����Ʈ
	int len; // ��� ����
}Path;

typedef struct Queue{
	int num;
	struct Queue *next;
}Queue;

typedef struct Queue_Head{
	struct Queue *front, *rear;
	int size;
}Queue_Head;

Graph graph[MAX];
V_info disGroup[MAX];
Path path;

Queue *CreateNode(int n) {
	Queue *newNode = (Queue *)malloc(sizeof(Queue));
	newNode->next = NULL;
	newNode->num = n;
	return newNode;
}

Queue_Head *QueueInit() {
	Queue_Head *queue = (Queue_Head *)malloc(sizeof(Queue_Head));
	queue->front = CreateNode(0);
	queue->rear = queue->front;
	queue->size = 1;
	return queue;
}

void enQueue(Queue_Head *queue, int v) {
	Queue *temp = queue->rear;
	temp->next = CreateNode(v);
	queue->rear = temp->next;
	queue->size++;
}

void deQueue(Queue_Head *queue) {
	Queue *temp = queue->front;
	queue->front = temp->next;
	queue->size--;
	free(temp);
}

void disGroupInit(int vertex) {
	V_info component; // ���� ���� ����ü ����
	component.distance = INF; // Ȯ�� ���� ���� �Ÿ��� INF
	component.visit = 0; // �湮���� ���� ����
	component.parent = -1; // �� ���� �ƹ� ������ �湮���� ����
	component.eNum = -1; // � ������ ��ġ�� ����
	for (int i = 0; i < vertex; i++)
		disGroup[i] = component;
	/* ���� ���� �迭�� ���� ������ INF�� �ʱ�ȭ ��Ű�� ���� ���� �ӽ� ���� */
}

void Dijkstra() { // �ִ� �Ÿ� && ��� ���ϴ� �Լ�
	disGroup[0].distance = 0;
	/* 0�� ���������� �Ÿ��� ��δ� 0(�ڱ� �ڽ�) */
	Queue_Head *queue = QueueInit();
	/* queue�� �̿��Ͽ� BFSŽ��, �켱 ���� ������ 0�� ���� ���� */
	while (queue->size) {
		int now = queue->front->num;
		disGroup[now].visit = 1;
		for (int i = 0; i < graph[now].len; i++) {
			/* �湮 ������ ��� ���� ������ ��� */
			Node near = graph[now].near[i]; // ���� ���� ��ȣ�� ����ġ ����
			int alt = disGroup[now].distance + near.w; // ���� ����� �� �������� �Ÿ�
			if (disGroup[near.v].distance > alt) {
				/* ���� ���������� ���� �˷��� �Ÿ����� ���� �˰Ե� �Ÿ��� �� ª�ٸ� ���� */
				disGroup[near.v].distance = alt; // �Ÿ� ����
				disGroup[near.v].parent = now; // ��� ����
				disGroup[near.v].eNum = near.eNum; // ���� ���� ����
				enQueue(queue, near.v); // ���� ������ �켱 ť�� ����
			}
			else if (disGroup[near.v].distance == alt) {
				if (disGroup[near.v].eNum < near.eNum) {
					/* ���� ���������� ���� �˷��� �Ÿ����� ���� �˰Ե� �Ÿ��� ������ ���� ���� ������ �Է� ������ �� ���ٸ� ���� */
					disGroup[near.v].parent = now; // ��� ����
					disGroup[near.v].eNum = near.eNum; // ���� ���� ����
				}
			}
		}
		deQueue(queue); // �湮�� ������ ť���� ��
	}
}

void CreatePath(int destination) { // �� ������ ���� ����� ����� �̿��Ͽ� ��� ����
	path.list[path.len++] = destination; // ���� ������ ���� ��ȣ ����
	int now = disGroup[destination].parent; // ���� �������� �����ϱ� �� ���� ��ȣ ����
	while (now != -1) { // ���� �������� �����ϱ� �� ���� ��ȣ�� -1�� �ƴ� ������ => 0�� ������ ������ ������
		path.list[path.len++] = now; // �� ���� ��ȣ�� �����ϰ�
		now = disGroup[now].parent; // �� ������ ���� ���� ����
	}
}

void Print(int vertex, FILE *out) { // ���� ��� �Լ�
	for (int i = 1; i < vertex; i++) {
		if (disGroup[i].visit != 0) { // �湮�� ���� ���� ���(��� ��ΰ� ����)
			CreatePath(i); // ��θ� �������� ������
			for (int i = path.len - 1; i >= 0; i--)
				fprintf(out, "V%d ", path.list[i]);
			fprintf(out, "(%d)\n", disGroup[i].distance);
		}
		else // �湮�� ���� ������(��ΰ� �������� ���� == �Ÿ� -1)
			fprintf(out, "V0 V%d (-1)\n", i);
		memset(path.list, 0, sizeof(int) * path.len);
		path.len = 0;
	}
}

int main() {
	FILE *inp = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");
	int vertex, edge; // ������ ������ ��
	fscanf(inp, "%d %d", &vertex, &edge);
	for (int i = 0; i < edge; i++) {
		int s; // ��� ����
		fscanf(inp, "%d ", &s);
		fscanf(inp, "%d %d", &graph[s].near[graph[s].len].v, &graph[s].near[graph[s].len].w);
		graph[s].near[graph[s].len++].eNum = i;
	}
	/* Input Data */
	disGroupInit(vertex);
	Dijkstra(); // �ִ� �Ÿ� && ��� ��� �� ��� ����
	Print(vertex, out);
	/* Output Data*/
	fclose(inp);
	fclose(out);
	return 0;
}