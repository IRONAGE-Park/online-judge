#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int main() {
	int testcase; 
	double x1, x2, y1, y2, r1, r2, between;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
		if (x1 == x2 && y1 == y2) { // ������ ����.
			if (r1 == r2) printf("-1\n"); // ������ ���� ���� ���
			else printf("0\n"); // ������ ������ ���̰� �ٸ� ��� = �ƿ� ������ �������� �ʴ´�.
		}
		else { // ������ �ٸ���.
			between = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // �� ���� ������ �Ÿ�
			if (between > r1 + r2) printf("0\n");
			else if (between == r1 + r2) printf("1\n");
			else {
				double l = (r1 > r2) ? r1 : r2;
				double s = (r1 > r2) ? r2 : r1;
				if (between + s > l) printf("2\n");
				else if (between + s == l) printf("1\n");
				else printf("0\n");
			}
		}
	}
	return 0;
}