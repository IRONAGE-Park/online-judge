#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#define MAX 5000

using namespace std;

ifstream inp;
ofstream out;

typedef struct { string str; int s, b; }Quest;

void Init(vector<string> &dp) {
	dp.reserve(MAX);
	for (char one = '1'; one <= '9'; one++) {
		for (char two = '1'; two <= '9'; two++) {
			if (one != two) {
				for (char three = '1'; three <= '9'; three++) {
					if (one != three && two != three) {
						for (char four = '1'; four <= '9'; four++) {
							if (one != four && two != four && three != four) {
								string data = "";
								data += one; data += two; data += three; data += four;
								dp.push_back(data);
							}
						}
					}
				}
			}
		}
	}
}

bool StrikeCheck(string tab, string Q, int strike) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (tab[i] == Q[i]) cnt++;
	}
	return strike == cnt;
}

bool BallCheck(string tab, string Q, int ball) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j && tab[i] == Q[j]) cnt++;
		}
	}
	return ball == cnt;
}

bool SBCheck(string tab, string Q, int strike, int ball) {
	return StrikeCheck(tab, Q, strike) && BallCheck(tab, Q, ball);
}

void Calculate(vector<string> &table, vector<Quest> &quest) {
	vector<string> newTable;
	newTable.reserve(MAX);
	for (int i = 0; i < table.size(); i++) {
		for (int j = 0; j < quest.size(); j++) {
			if (!SBCheck(table[i], quest[j].str, quest[j].s, quest[j].b))
				break;
			if (j == quest.size() - 1) newTable.push_back(table[i]);
		}
	}
	table = newTable;
}

void Print(vector<string> &table) {
	out << table.size() << '\n';
	if (table.size() <= 6) {
		for (int i = 0; i < table.size(); i++)
			out << table[i] << '\n';
	}
	else {
		for (int i = 0; i < 3; i++) {
			out << table[i] << '\n';
		}
		for (int i = 3; i >= 1; i--) {
			out << table[table.size() - i] << '\n';
		}
	}
}

int main() {
	inp.open("numgame.inp");
	out.open("numgame.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		vector<string> table;
		vector<Quest> quest;
		Init(table);
		int n;
		inp >> n;
		for (int i = 0; i < n; i++) {
			Quest q;
			inp >> q.str >> q.s >> q.b;
			quest.push_back(q);
		}
		Calculate(table, quest);
		Print(table);
		table.clear();
	}
	inp.close();
	out.close();
	return 0;
}