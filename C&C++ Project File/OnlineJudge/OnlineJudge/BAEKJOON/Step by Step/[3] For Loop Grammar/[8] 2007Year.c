#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int month, day, D = 0;
	scanf("%d %d", &month, &day);
	while (month > 1) {
		if (month > 8) {
			if (month % 2 == 1) D += 31;
			else D += 30;
		}
		else {
			if (month % 2 == 1 && month != 3) D += 30;
			else if (month == 3) D += 28;
			else D += 31;
		}
		month--;
	}
	D += day;
	if (D % 7 == 1) printf("MON");
	else if (D % 7 == 2) printf("TUE");
	else if (D % 7 == 3) printf("WED");
	else if (D % 7 == 4) printf("THU");
	else if (D % 7 == 5) printf("FRI");
	else if (D % 7 == 6) printf("SAT");
	else printf("SUN");
	printf("\n");
	return 0;
}