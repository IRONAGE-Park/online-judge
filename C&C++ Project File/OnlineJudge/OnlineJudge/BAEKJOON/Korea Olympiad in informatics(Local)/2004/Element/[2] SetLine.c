#include<stdio.h>

int main() {
	int line[100];
	int num, card;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &card);
		for (int j = 0; j <= card; j++) {
			line[i - j + 1] = line[i - j];
		}
		line[i - card] = i + 1;
	}

	for (int i = 0; i < num; i++) {
		printf("%d ", line[i]);
	}
	return 0;
}