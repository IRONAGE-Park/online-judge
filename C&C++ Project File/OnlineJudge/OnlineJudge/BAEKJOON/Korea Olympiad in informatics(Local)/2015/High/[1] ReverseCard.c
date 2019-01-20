#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int cnt = 0, start, end;
	int card[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 }, Rcard[20];
	while (cnt < 10) {
		scanf("%d %d", &start, &end);
		int c = start - 1;
		int r = end - 1;

		for (int i = 0; i < 20; i++) {
			Rcard[i] = card[i];
		}

		for (int i = end; i >= start; i--) {
			card[c] = Rcard[r];
			c++;
			r--;
		}
		cnt++;
	}
	for (int i = 0; i < 20; i++) {
		printf("%d ", card[i]);
	}
	printf("\n");
	return 0;
}
