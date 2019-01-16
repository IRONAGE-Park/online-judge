#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int abs(int n) {
	if (n < 0) return -n;
	else return n;
}

vector<int> Reverse(vector<int> poly) { // 어떤 한 다각형 배열을 Reverse.
	vector<int> r_poly;
	r_poly.reserve(poly.size());
	for (int i = poly.size() - 1; i >= 0; i--) {
		int j = (i + 1) % poly.size();
		if ((poly[i] > 0)) r_poly.push_back(-abs(poly[j]));
		else r_poly.push_back(abs(poly[j]));
	}
	return r_poly;
}

bool Compare(vector<int> poly1, vector<int> poly2) { // 두 배열 일치 불 일치 판정
	for (int i = poly1.size(); i != 0; i--) {
		if (poly1 == poly2) return true;
		else {
			poly1.push_back(poly1.at(0));
			poly1.erase(poly1.begin());
		}
	}
	return false;
}

bool Solution(vector<int> poly1, vector<int> poly2) { // 결과 출력
	if (Compare(poly1, poly2)) return true;
	else {
		poly2 = Reverse(poly2);
		if (Compare(poly1, poly2)) return true;
		else return false;
	}
}

int main() {
	ifstream inp("poly.inp");
	ofstream out("poly.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int N;
		inp >> N;
		vector<int> poly1(N), poly2(N);
		for (int i = 0; i < N; i++) inp >> poly1[i];
		for (int i = 0; i < N; i++) inp >> poly2[i];
		out << Solution(poly1, poly2) << '\n';
		poly1.clear(), poly2.clear();
	}
	inp.close();
	out.close();
	return 0;
}