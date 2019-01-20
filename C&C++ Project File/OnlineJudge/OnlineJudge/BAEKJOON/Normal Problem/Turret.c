#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)

int main() {
	int testcase; 
	double x1, x2, y1, y2, r1, r2, between;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
		if (x1 == x2 && y1 == y2) { // 중점이 같다.
			if (r1 == r2) printf("-1\n"); // 완전히 같은 원일 경우
			else printf("0\n"); // 중점이 같으나 길이가 다를 경우 = 아예 접점이 존재하지 않는다.
		}
		else { // 중점이 다르다.
			between = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // 두 중점 사이의 거리
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