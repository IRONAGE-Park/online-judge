#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	int TC, a, b, num;
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		scanf("%d %d", &a, &b);
		num = a;
		for (int j = 1; j < b; j++) {
			num *= a;
			if (num >= 10) num = num % 10;
		}
		if (num % 10 != 0) printf("%d\n", num);
		else printf("10\n");
	}
	return 0;
}