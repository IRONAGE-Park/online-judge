#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
#define MAX 1000000

using namespace std;

int treeCheck(vector<int> &parent, vector<int> &child) {
	int root = -1;
	for (int p_i = 0, c_i = 0; c_i < child.size() - 1;) {
		if (child[c_i] == child[c_i + 1]) return -1;
		while (p_i < parent.size() - 1 && parent[p_i] == parent[p_i + 1]) 
			p_i++;
		if (p_i < parent.size()) {
			int candidate = parent[p_i++];
			while (c_i < child.size() && candidate > child[c_i])
				c_i++;
			if (candidate != child[c_i]) {
				if (root != -1) return -1;
				root = candidate;
			}
		}
		else c_i++;
	}
	return root;
}

int main() {
	FILE *inp = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");
	vector<int> parent, child;
	for (int T = 1;; T++) {
		int p, c;
		parent.reserve(MAX); child.reserve(MAX);
		while (true) {
			fscanf(inp, "%d %d", &p, &c);
			if (p == -1 && c == -1) return 0;
			else if (!p && !c) break;
			else { parent.push_back(p); child.push_back(c); }
		}
		sort(parent.begin(), parent.end());
		sort(child.begin(), child.end());
		fprintf(out, "Test Case %d: %d\n", T, treeCheck(parent, child));
		parent.clear(); child.clear();
	}
	fclose(inp);
	fclose(out);
	return 0;
}