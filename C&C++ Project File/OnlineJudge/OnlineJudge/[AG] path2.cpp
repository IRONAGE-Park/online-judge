#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#define MAX 100
#define MOD 100000

using namespace std;

typedef enum { END, LEFT, UP }VECTOR;
typedef struct { int x, y; }Point; // 좌표 구조체
typedef struct {
	bool exist; // 존재하는지 하지 않는지
	int vt;
	int count, cost; // 그 k수로 가는 모든 경로 수와 최단 비용
}Element;
typedef struct {
	bool mark; // 그 지역에 X_Marking이 있는지
	vector<Element> kList; // 각 K에 대한 리스트
}Board; // 각 보드 구조체

Board board[MAX][MAX]; // 도로
int horizontal[MAX][MAX], vertical[MAX][MAX], maxK; // 수직 수평 비용 리스트

void TableInit(int M, int N, int K, Element init) { // DP Table을 만들기 위해 초기값 지정
	maxK = 0;
	board[0][0].kList.resize(K + 1, init);
	board[0][0].kList[0].count = 1;
	board[0][0].kList[0].exist = true;
	board[0][0].kList[0].vt = END;
	if (board[0][0].mark) { // 그 지점이 마킹되어있으면
		board[0][0].kList[1] = board[0][0].kList[0];
		board[0][0].kList[0].exist = false;
		maxK++;
	}
	for (int i = 1; i < M; i++) {
		board[i][0].kList.resize(K + 1, init);
		for (int k = 0; k <= maxK; k++) {
			if (board[i - 1][0].kList[k].exist) { // 그 지점을 k번 거쳐서 가는 경로가 있으면,
				board[i][0].kList[k].vt = UP;
				board[i][0].kList[k].cost = board[i - 1][0].kList[k].cost + vertical[i - 1][0];
				board[i][0].kList[k].exist = true;
				board[i][0].kList[k].count = board[i - 1][0].kList[k].count;
				if (board[i][0].mark) { // 그 지점이 마킹되어있으면
					board[i][0].kList[k + 1] = board[i][0].kList[k];
					board[i][0].kList[k].exist = false;
					if (k == maxK) { maxK++; break; }
				}
			}
		}
	}
	for (int j = 1; j < N; j++) {
		board[0][j].kList.resize(K + 1, init);
		for (int k = 0; k <= maxK; k++) {
			if (board[0][j - 1].kList[k].exist) { // 그 지점을 k번 거쳐서 가는 경로가 있으면,
				board[0][j].kList[k].vt = LEFT;
				board[0][j].kList[k].cost = board[0][j - 1].kList[k].cost + horizontal[0][j - 1];
				board[0][j].kList[k].exist = true;
				board[0][j].kList[k].count = board[0][j - 1].kList[k].count;
				if (board[0][j].mark) { // 그 지점이 마킹되어있으면
					board[0][j].kList[k + 1] = board[0][j].kList[k];
					board[0][j].kList[k].exist = false;
					if (k == maxK) { maxK++; break; }
				}
			}
		}
	}
}

void DP(int M, int N, int K) {
	Element init; // 초기화 용 변수
	init.cost = 0; init.count = 0; init.exist = false;
	TableInit(M, N, K, init);
	/* 출발 점과 첫째 라인의 초기 값 설정 */
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			board[i][j].kList.resize(K + 1, init);
			for (int k = 0; k <= maxK; k++) {
				if (board[i - 1][j].kList[k].exist || board[i][j - 1].kList[k].exist) { // 그 지점을 k번 거쳐서 가는 경로가 있으면,
					Element temp;
					temp.exist = true;
					if (board[i - 1][j].kList[k].exist && board[i][j - 1].kList[k].exist) { // k번 거쳐서 가능 경로가 둘 다 있으면,
						temp.count = (board[i - 1][j].kList[k].count + board[i][j - 1].kList[k].count) % MOD;
						/* 여기까지 k번 거쳐서 올 수 있는 경우의 수는 양 방향의 합 */
						if (board[i][j - 1].kList[k].cost + horizontal[i][j - 1] > board[i - 1][j].kList[k].cost + vertical[i - 1][j]) {
							// 위쪽에서 오는 경우가 비용이 더 작으면
							temp.vt = UP;
							temp.cost = board[i - 1][j].kList[k].cost + vertical[i - 1][j];
						}
						else {
							// 왼쪽에서 오는 경우가 더 비용이 작으면
							temp.vt = LEFT;
							temp.cost = board[i][j - 1].kList[k].cost + horizontal[i][j - 1];
						}
					}
					else if (board[i - 1][j].kList[k].exist) { // 위 쪽에서 k번 거쳐서 내려오는 경우
						temp.vt = UP;
						temp.cost = board[i - 1][j].kList[k].cost + vertical[i - 1][j];
						temp.count = board[i - 1][j].kList[k].count;
					}
					else { // 왼 쪽에서 k번 거쳐서 오는 경우
						temp.vt = LEFT;
						temp.cost = board[i][j - 1].kList[k].cost + horizontal[i][j - 1];
						temp.count = board[i][j - 1].kList[k].count;
					}
					if (board[i][j].mark) { // 그 지점이 마킹되어있으면
						board[i][j].kList[k + 1] = temp;
						if (k == maxK) { maxK++; break; }
					}
					else
						board[i][j].kList[k] = temp;
				}
			}
		}
	}
}

int main() {
	ifstream inp("path.inp");
	ofstream out("path.out");
	int testcase;
	inp >> testcase;
	for (int T = 1; T <= testcase; T++) {
		int M, N, K;
		inp >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			Point p;
			inp >> p.x >> p.y;
			board[p.x][p.y].mark = true;
		}
		for (int i = 0; i < M; i++) for (int j = 0; j < N - 1; j++) inp >> horizontal[i][j];
		for (int i = 0; i < M - 1; i++) for (int j = 0; j < N; j++) inp >> vertical[i][j];
		DP(M, N, K);
		out << "Test Case No:" << T << '\n';
		for (int k = 0; k <= K; k++) {
			if (board[M - 1][N - 1].kList[k].exist && board[M - 1][N - 1].kList[k].count != 0) {
				out << "k:" << k;
				out << " count:" << board[M - 1][N - 1].kList[k].count << " cost:" << board[M - 1][N - 1].kList[k].cost << '\n';
				vector<Point> storePath;
				storePath.reserve(M + N);
				int curI = M - 1, curJ = N - 1, curK = k;
				while (curI != 0 || curJ != 0) {
					Point p = { curI, curJ };
					storePath.push_back(p);
					if (board[curI][curJ].kList[curK].vt == LEFT) {
						if (board[curI][curJ].mark) curK--;
						curJ--;
					}
					else {
						if (board[curI][curJ].mark) curK--;
						curI--;
					}
				}
				Point zero = { 0, 0 };
				storePath.push_back(zero);
				for (int i = storePath.size() - 1; i >= 0; i--) {
					out << '(' << storePath[i].x << ',' << storePath[i].y << ')';
					if (i != 0)
						out << "->";
				}
				storePath.clear();

				out << '\n';
			}
		}
		out << '\n';
		memset(board, 0, sizeof(board));
	}
	inp.close();
	out.close();
	return 0;
}