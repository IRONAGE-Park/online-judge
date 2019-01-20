#include<stdio.h>

int main() {
	int n, std;
	scanf("%d %d", &n, &std);
	while (n--) {
		int num;
		scanf("%d", &num);
		if (num < std) printf("%d ", num);
	}
	return 0;
}