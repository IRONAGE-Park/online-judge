#include<iostream>
#include<fstream>
#include<string>

using namespace std;

ifstream inp;
ofstream out;

bool GoodCharacter(string G, char c) {
	for (int i = 0; i < G.length(); i++)
		if (G[i] == c) return true;
	return false;
}

bool StarChecker(string star, string G) {
	bool correct = true;
	for (int i = 0; i < star.length(); i++) {
		correct = false;
		if (!GoodCharacter(G, star[i]))
			return true;
	}
	return correct;
}

bool CheckQuestion(string P, string Q, string G) {
	for (int p_i = 0, q_i = 0; p_i < P.length(); p_i++, q_i++) {
		switch (P[p_i]) {
		case '?':
			if (!GoodCharacter(G, Q[q_i]))
				return false;
			break;
		case '*':
			q_i += Q.length() - P.length();
			if (!StarChecker(Q.substr(p_i, Q.length() - P.length() + 1), G))
				return false;
			break;
		default:
			if (P[p_i] != Q[q_i])
				return false;
		}
	}
	return true;
}

int main() {
	inp.open("exam.inp");
	out.open("exam.out");
	int testcase;
	inp >> testcase;
	inp.get();
	for (int T = 1; T <= testcase; T++) {
		string P, Q, G;
		inp >> G >> P;
		int q_num;
		inp >> q_num;
		inp.get();
		out << "Test Case: #" << T << '\n';
		for (int i = 0; i < q_num; i++) {
			inp >> Q;
			if (CheckQuestion(P, Q, G)) out << "Yes\n";
			else out << "No\n";
		}
	}
	inp.close();
	out.close();
	return 0;
}