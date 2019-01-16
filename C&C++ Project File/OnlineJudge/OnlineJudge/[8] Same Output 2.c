#include<stdio.h>

int main() {
	char str[101];
	while (fgets(str, 101, stdin) != NULL)
		printf("%s", str);

	return 0;
}