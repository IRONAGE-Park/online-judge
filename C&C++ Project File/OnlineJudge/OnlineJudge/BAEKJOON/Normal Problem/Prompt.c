#include<stdio.h>
#pragma warning(disable:4996)
#define MAX 51

int N;
char name[MAX][MAX];
char search[MAX];

void compare(int v, int w) {
	if (name[v][w] == name[v + 1][w]) {
		if (v + 1 == N - 1) {
			search[w] = name[v][w];
		}
		else {
			compare(v + 1, w);
		}
	}
	else {
		search[w] = '?';
	}
}

int main() {
	int length = MAX;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &name[i]);
		for (int j = 0;; j++) {
			if (name[i][j] == 0) {
				if (i >= 1 && length != j) {
					printf("---파일 이름의 길이가 다릅니다.---\n", length);
					i--;
					continue;
				}
				length = j;
				break;
			}
		}
	}
	if (N > 1) {
		for (int i = 0; i < length; i++) compare(0, i);
		printf("%s\n", search);
	}
	else printf("%s\n", name[0]);
	return 0;
}