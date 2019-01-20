#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
	int y, m, d;
	bool state; // true = start, end = false;
}Timeline;

bool compare(Timeline a, Timeline b) {
	if (a.y == b.y) {
		if (a.m == b.m) {
			if (a.d == b.d)
				return a.state < b.state;
			return a.d < b.d;
		}
		return a.m < b.m;
	}
	return a.y < b.y;
}

int RowCounting(vector<Timeline> &chart, int N) {
	int max_cnt = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (chart[i].state) {
			if (++cnt > max_cnt)
				max_cnt = cnt;
		}
		else
			cnt--;
	}
	return max_cnt;
}

int main() {
	ifstream inp("timeline.inp");
	ofstream out("timeline.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int N;
		inp >> N;
		N *= 2;
		vector<Timeline> chart(N);
		for (int i = 0; i < N; i++) {
			char c;
			inp >> chart[i].y >> c >> chart[i].m >> c >> chart[i].d;
			if (i % 2 == 0) chart[i].state = true;
		}
		sort(chart.begin(), chart.end(), compare);
		out << RowCounting(chart, N) << '\n';
	}
	inp.close();
	out.close();
	return 0;
}
