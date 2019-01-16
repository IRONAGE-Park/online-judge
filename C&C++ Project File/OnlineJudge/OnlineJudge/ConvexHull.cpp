#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#define PI 3.14159
#define MAX 100000

using namespace std;

typedef struct { int x, y; double angle; }Point; // 점 구조체
bool operator<(Point p1, Point p2) {
	if (p1.angle == p2.angle);
	return p1.angle < p2.angle;
}
int ccw(Point p1, Point p2, Point p3) {
	int temp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	temp = temp - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
	if (temp > 0) { // 반시계
		return 1;
	}
	else if (temp < 0) { // 시계
		return -1;
	}
	else { // 일직선
		return 0;
	}
}
int n, min_Index, convexCnt; // n = 점의 개수, min_Index = 가장 아래에 있는 점
Point point[MAX];

void swap(Point *p1, Point *p2) {
	Point temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void MinY_Index() {
	for (int i = 1; i < n; i++) {
		if (point[min_Index].y > point[i].y) min_Index = i;
		if (point[min_Index].y == point[i].y) if (point[min_Index].x > point[i].x) min_Index = i;
	}
	point[min_Index].angle = 0.0; // 0번 인덱스의 각도는 0도
	swap(&point[0], &point[min_Index]); // 모두 계산한 뒤 0번 인덱스에 가장 작은 점 넣음.
}
/* y축 기준으로 가장 아래에 있는 점 찾기 -> 가장 아래에 있는 점이 여러 개면 가장 왼 쪽을 선택 */

void Computing_Angle() {
	for (int i = 1; i < n; i++) {
		int cx = point[i].x - point[0].x, cy = point[i].y - point[0].y;
		point[i].angle = atan2(cy, cx);
		point[i].angle *= (180 / PI);
	}
}
/* 가장 아래의 점과 나머지 점들의 각도 계산 */

void ConvexHull() {
	stack<int> s;
	s.push(0);
	s.push(1);
	int next = 2;
	// 모든 점을 훑음
	while (next < n) {
		// 스택에 2개 이상의 점이 남아있는 한...
		while (s.size() >= 2) {
			int first, second;
			first = s.top();
			s.pop();
			second = s.top();
			// 스택 최상단 점 2개와 다음 점의 관계가 CCW일 때까지 스택 pop
			if (ccw(point[second], point[first], point[next]) > 0) {
				s.push(first);
				break;
			}
		}
		// 다음 점을 스택에 넣음
		s.push(next++);
	}
	// 이제 스택에 컨벡스 헐 정점들이 순서대로 쌓여 있음
	convexCnt = s.size();
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> point[i].x >> point[i].y; 
	/* INPUT */

	MinY_Index();
	Computing_Angle();
	sort(point, point + n);
	ConvexHull();
	
	cout << convexCnt << '\n';
	/* OUTPUT */
	return 0;
}