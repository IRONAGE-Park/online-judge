#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#define MAX 10000
#define INF 0x7FFFFFFF

typedef struct {
	int v, w; // 대상 정점과 그 정점까지의 가중치
	int eNum; // 간선의 들어온 순서
}Node;
// 그래프의 정점 구조체

typedef struct {
	Node near[MAX]; // 인접 노드
	int len; // 인접 노드 갯수
}Graph;
// 그래프의 형태 구조체

typedef struct {
	int distance; // 최단 거리
	int parent; // 최단 경로를 저장하기 위해 바로 전에 지나친 정점 저장
	int eNum; // 형식에 맞게 경로 출력하기 위해 사용된 간선의 입력 순서 저장
	int visit; // 정점 방문 여부
}V_info;
// 각 정점의 정보를 저장하는 구조체

typedef struct {
	int list[MAX]; // 경로 리스트
	int len; // 경로 길이
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
	V_info component; // 정점 정보 구조체 선언
	component.distance = INF; // 확인 되지 않은 거리는 INF
	component.visit = 0; // 방문하지 않은 상태
	component.parent = -1; // 이 전에 아무 정점도 방문하지 않음
	component.eNum = -1; // 어떤 간선도 거치지 않음
	for (int i = 0; i < vertex; i++)
		disGroup[i] = component;
	/* 정점 정보 배열의 내부 값들을 INF로 초기화 시키기 위해 만든 임시 변수 */
}

void Dijkstra() { // 최단 거리 && 경로 구하는 함수
	disGroup[0].distance = 0;
	/* 0번 정점까지의 거리와 경로는 0(자기 자신) */
	Queue_Head *queue = QueueInit();
	/* queue를 이용하여 BFS탐색, 우선 시작 정점인 0번 정점 삽입 */
	while (queue->size) {
		int now = queue->front->num;
		disGroup[now].visit = 1;
		for (int i = 0; i < graph[now].len; i++) {
			/* 방문 정점의 모든 인접 정점을 고려 */
			Node near = graph[now].near[i]; // 인접 정점 번호와 가중치 저장
			int alt = disGroup[now].distance + near.w; // 새로 계산한 그 노드까지의 거리
			if (disGroup[near.v].distance > alt) {
				/* 인접 정점까지의 원래 알려진 거리보다 새로 알게된 거리가 더 짧다면 갱신 */
				disGroup[near.v].distance = alt; // 거리 갱신
				disGroup[near.v].parent = now; // 경로 갱신
				disGroup[near.v].eNum = near.eNum; // 사용된 간선 갱신
				enQueue(queue, near.v); // 인접 정점을 우선 큐에 삽입
			}
			else if (disGroup[near.v].distance == alt) {
				if (disGroup[near.v].eNum < near.eNum) {
					/* 인접 정점까지의 원래 알려진 거리보다 새로 알게된 거리가 같더라도 새로 사용된 간선의 입력 순서가 더 높다면 갱신 */
					disGroup[near.v].parent = now; // 경로 갱신
					disGroup[near.v].eNum = near.eNum; // 사용된 간선 갱신
				}
			}
		}
		deQueue(queue); // 방문한 정점은 큐에서 뺌
	}
}

void CreatePath(int destination) { // 각 정점에 이전 노드의 기록을 이용하여 경로 만듬
	path.list[path.len++] = destination; // 최종 목적지 정점 번호 삽입
	int now = disGroup[destination].parent; // 최종 목적지에 도달하기 전 정점 번호 저장
	while (now != -1) { // 최종 목적지에 도달하기 전 정점 번호가 -1이 아닐 때까지 => 0번 정점에 도달할 때까지
		path.list[path.len++] = now; // 그 정점 번호를 삽입하고
		now = disGroup[now].parent; // 그 정점의 이전 정점 저장
	}
}

void Print(int vertex, FILE *out) { // 정점 출력 함수
	for (int i = 1; i < vertex; i++) {
		if (disGroup[i].visit != 0) { // 방문한 적이 있을 경우(적어도 경로가 존재)
			CreatePath(i); // 경로를 역순으로 저장함
			for (int i = path.len - 1; i >= 0; i--)
				fprintf(out, "V%d ", path.list[i]);
			fprintf(out, "(%d)\n", disGroup[i].distance);
		}
		else // 방문한 적이 없으면(경로가 존재하지 않음 == 거리 -1)
			fprintf(out, "V0 V%d (-1)\n", i);
		memset(path.list, 0, sizeof(int) * path.len);
		path.len = 0;
	}
}

int main() {
	FILE *inp = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");
	int vertex, edge; // 정점과 간선의 수
	fscanf(inp, "%d %d", &vertex, &edge);
	for (int i = 0; i < edge; i++) {
		int s; // 출발 정점
		fscanf(inp, "%d ", &s);
		fscanf(inp, "%d %d", &graph[s].near[graph[s].len].v, &graph[s].near[graph[s].len].w);
		graph[s].near[graph[s].len++].eNum = i;
	}
	/* Input Data */
	disGroupInit(vertex);
	Dijkstra(); // 최단 거리 && 경로 계산 후 결과 저장
	Print(vertex, out);
	/* Output Data*/
	fclose(inp);
	fclose(out);
	return 0;
}