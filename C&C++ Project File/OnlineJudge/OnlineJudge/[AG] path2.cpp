#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#define MAX 100
#define MOD 100000

using namespace std;

typedef enum { END, LEFT, UP }VECTOR;
typedef struct { int x, y; }Point; // ��ǥ ����ü
typedef struct {
	bool exist; // �����ϴ��� ���� �ʴ���
	int vt;
	int count, cost; // �� k���� ���� ��� ��� ���� �ִ� ���
}Element;
typedef struct {
	bool mark; // �� ������ X_Marking�� �ִ���
	vector<Element> kList; // �� K�� ���� ����Ʈ
}Board; // �� ���� ����ü

Board board[MAX][MAX]; // ����
int horizontal[MAX][MAX], vertical[MAX][MAX], maxK; // ���� ���� ��� ����Ʈ

void TableInit(int M, int N, int K, Element init) { // DP Table�� ����� ���� �ʱⰪ ����
	maxK = 0;
	board[0][0].kList.resize(K + 1, init);
	board[0][0].kList[0].count = 1;
	board[0][0].kList[0].exist = true;
	board[0][0].kList[0].vt = END;
	if (board[0][0].mark) { // �� ������ ��ŷ�Ǿ�������
		board[0][0].kList[1] = board[0][0].kList[0];
		board[0][0].kList[0].exist = false;
		maxK++;
	}
	for (int i = 1; i < M; i++) {
		board[i][0].kList.resize(K + 1, init);
		for (int k = 0; k <= maxK; k++) {
			if (board[i - 1][0].kList[k].exist) { // �� ������ k�� ���ļ� ���� ��ΰ� ������,
				board[i][0].kList[k].vt = UP;
				board[i][0].kList[k].cost = board[i - 1][0].kList[k].cost + vertical[i - 1][0];
				board[i][0].kList[k].exist = true;
				board[i][0].kList[k].count = board[i - 1][0].kList[k].count;
				if (board[i][0].mark) { // �� ������ ��ŷ�Ǿ�������
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
			if (board[0][j - 1].kList[k].exist) { // �� ������ k�� ���ļ� ���� ��ΰ� ������,
				board[0][j].kList[k].vt = LEFT;
				board[0][j].kList[k].cost = board[0][j - 1].kList[k].cost + horizontal[0][j - 1];
				board[0][j].kList[k].exist = true;
				board[0][j].kList[k].count = board[0][j - 1].kList[k].count;
				if (board[0][j].mark) { // �� ������ ��ŷ�Ǿ�������
					board[0][j].kList[k + 1] = board[0][j].kList[k];
					board[0][j].kList[k].exist = false;
					if (k == maxK) { maxK++; break; }
				}
			}
		}
	}
}

void DP(int M, int N, int K) {
	Element init; // �ʱ�ȭ �� ����
	init.cost = 0; init.count = 0; init.exist = false;
	TableInit(M, N, K, init);
	/* ��� ���� ù° ������ �ʱ� �� ���� */
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			board[i][j].kList.resize(K + 1, init);
			for (int k = 0; k <= maxK; k++) {
				if (board[i - 1][j].kList[k].exist || board[i][j - 1].kList[k].exist) { // �� ������ k�� ���ļ� ���� ��ΰ� ������,
					Element temp;
					temp.exist = true;
					if (board[i - 1][j].kList[k].exist && board[i][j - 1].kList[k].exist) { // k�� ���ļ� ���� ��ΰ� �� �� ������,
						temp.count = (board[i - 1][j].kList[k].count + board[i][j - 1].kList[k].count) % MOD;
						/* ������� k�� ���ļ� �� �� �ִ� ����� ���� �� ������ �� */
						if (board[i][j - 1].kList[k].cost + horizontal[i][j - 1] > board[i - 1][j].kList[k].cost + vertical[i - 1][j]) {
							// ���ʿ��� ���� ��찡 ����� �� ������
							temp.vt = UP;
							temp.cost = board[i - 1][j].kList[k].cost + vertical[i - 1][j];
						}
						else {
							// ���ʿ��� ���� ��찡 �� ����� ������
							temp.vt = LEFT;
							temp.cost = board[i][j - 1].kList[k].cost + horizontal[i][j - 1];
						}
					}
					else if (board[i - 1][j].kList[k].exist) { // �� �ʿ��� k�� ���ļ� �������� ���
						temp.vt = UP;
						temp.cost = board[i - 1][j].kList[k].cost + vertical[i - 1][j];
						temp.count = board[i - 1][j].kList[k].count;
					}
					else { // �� �ʿ��� k�� ���ļ� ���� ���
						temp.vt = LEFT;
						temp.cost = board[i][j - 1].kList[k].cost + horizontal[i][j - 1];
						temp.count = board[i][j - 1].kList[k].count;
					}
					if (board[i][j].mark) { // �� ������ ��ŷ�Ǿ�������
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