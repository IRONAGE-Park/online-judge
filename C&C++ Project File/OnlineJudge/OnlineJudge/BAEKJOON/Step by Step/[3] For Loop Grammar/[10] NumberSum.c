#include<stdio.h>

int main() {
	int n, sum = 0;
	scanf("%d\n", &n);
	while (n--) {
		char num;
		scanf("%c", &num);
		sum += (int)num - 48;
	}
	printf("%d", sum);
	return 0;
}