#include<iostream>
#include<cstring>

int main() {
	char str[100010];
	std::cin >> str;
	int num = 0, tot_num = 0, result = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			num++, tot_num++;
		}
		else {
			if (str[i - 1] == '(') {
				num--, tot_num--;
				result += num;
			}
			else {
				num--;
			}
		}
	}
	std::cout << result + tot_num;
	return 0;
}