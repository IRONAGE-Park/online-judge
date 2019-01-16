#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char *str = (char*)malloc(sizeof(char) * 100000000);
	int cnt = 0;
	gets(str);
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == ' ') cnt++;
	if (strlen(str) == 0) printf("0\n");
	else {
		if (str[0] == ' ') cnt--;
		if (str[strlen(str) - 1] == ' ') cnt--;
		printf("%d", cnt + 1);
	}
	return 0;
}