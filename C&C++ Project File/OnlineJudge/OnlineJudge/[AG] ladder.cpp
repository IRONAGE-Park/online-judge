#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#define MAX 20000

using namespace std;

typedef struct Node {
	int x; // x좌표
	int index; // 매핑된 Map의 인덱스
	int height; // 높이
	int connX, connIdx; // 연결된 다른 노드
}Node;

typedef struct {
	int height; // 높이
	int MapX, MapIdx; // 매핑된 Node의 x좌표와 인덱스
}Map;

bool compare(Map a, Map b) {
	return b.height < a.height;
}

void solution(vector< vector<Node> > &ladder, vector< vector<Map> > &map, vector<int> &answer) {
	for (int line = 0; line < ladder.size(); line++) {
		Map temp = map[line][0];
		while (temp.height != -1) {
			temp = map[ladder[ladder[temp.MapX][temp.MapIdx].connX][ladder[temp.MapX][temp.MapIdx].connIdx].x][ladder[ladder[temp.MapX][temp.MapIdx].connX][ladder[temp.MapX][temp.MapIdx].connIdx].index + 1];
		}
		answer[temp.MapX] = line;
	}
}

int main() {
	ifstream inp("ladder.inp");
	ofstream out("ladder.out");

	int N;
	inp >> N;
	vector< vector<Node> > ladder(N);
	vector< vector<Map> > map(N);
	while (true) {
		int x1, y1, x2, y2;
		inp >> x1 >> y1 >> x2 >> y2;
		if (!x1 && !y1 && !x2 && !y2) break;
		Node n1, n2;
		Map m1, m2;
		n1.x = x1; n2.x = x2; n1.height = y1; n2.height = y2;
		n1.connX = x2; n2.connX = x1;
		n1.connIdx = (int)ladder[x2].size() + 1; n2.connIdx = (int)ladder[x1].size() + 1;
		if (x1 == x2) n1.connIdx++;
		ladder[x1].push_back(n1); ladder[x2].push_back(n2);
		m1.height = y1; m2.height = y2;
		m1.MapX = x1; m2.MapX = x2;
		m1.MapIdx = n2.connIdx; m2.MapIdx = n1.connIdx;
		map[x1].push_back(m1); map[x2].push_back(m2);
	}
	for (int i = 0; i < N; i++) {
		Map top, bot;
		top.height = MAX; top.MapIdx = 0; top.MapX = i, bot.height = -1, bot.MapX = i;
		Node Top;
		Top.connIdx = 0; Top.connX = i; Top.x = i; Top.index = 0; Top.height = MAX;
		map[i].push_back(top); ladder[i].insert(ladder[i].begin(), Top);
		sort(map[i].begin(), map[i].end(), compare);
		map[i].push_back(bot);
		for (int j = 1; j < map[i].size() - 1; j++)
			ladder[map[i][j].MapX][map[i][j].MapIdx].index = j;
	}
	vector<int> answer(ladder.size());
	solution(ladder, map, answer);
	for (int i = 0; i < N; i++) {
		out << answer[i] << ' ';
	}
	out << '\n';
	inp.close();
	out.close();
	return 0;
}