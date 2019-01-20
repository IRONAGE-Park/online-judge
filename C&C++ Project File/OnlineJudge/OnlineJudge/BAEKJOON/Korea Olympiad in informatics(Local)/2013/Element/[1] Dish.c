#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	char c, beforeC;
	c = 0, beforeC = 0;
	scanf("%c", &beforeC);
	int sum = 10;
	while (1) {
		scanf("%c", &c);
		if (c == '\n') {
			printf("%d\n", sum);
			break;
		}
		if (c != beforeC) sum += 10;
		else if (c == beforeC) sum += 5;
		beforeC = c;
	}
	return 0;
}