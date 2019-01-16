#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#define PI 3.14159
#define MAX 100000

using namespace std;

typedef struct { int x, y; double angle; }Point; // �� ����ü
bool operator<(Point p1, Point p2) {
	if (p1.angle == p2.angle);
	return p1.angle < p2.angle;
}
int ccw(Point p1, Point p2, Point p3) {
	int temp = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	temp = temp - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
	if (temp > 0) { // �ݽð�
		return 1;
	}
	else if (temp < 0) { // �ð�
		return -1;
	}
	else { // ������
		return 0;
	}
}
int n, min_Index, convexCnt; // n = ���� ����, min_Index = ���� �Ʒ��� �ִ� ��
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
	point[min_Index].angle = 0.0; // 0�� �ε����� ������ 0��
	swap(&point[0], &point[min_Index]); // ��� ����� �� 0�� �ε����� ���� ���� �� ����.
}
/* y�� �������� ���� �Ʒ��� �ִ� �� ã�� -> ���� �Ʒ��� �ִ� ���� ���� ���� ���� �� ���� ���� */

void Computing_Angle() {
	for (int i = 1; i < n; i++) {
		int cx = point[i].x - point[0].x, cy = point[i].y - point[0].y;
		point[i].angle = atan2(cy, cx);
		point[i].angle *= (180 / PI);
	}
}
/* ���� �Ʒ��� ���� ������ ������ ���� ��� */

void ConvexHull() {
	stack<int> s;
	s.push(0);
	s.push(1);
	int next = 2;
	// ��� ���� ����
	while (next < n) {
		// ���ÿ� 2�� �̻��� ���� �����ִ� ��...
		while (s.size() >= 2) {
			int first, second;
			first = s.top();
			s.pop();
			second = s.top();
			// ���� �ֻ�� �� 2���� ���� ���� ���谡 CCW�� ������ ���� pop
			if (ccw(point[second], point[first], point[next]) > 0) {
				s.push(first);
				break;
			}
		}
		// ���� ���� ���ÿ� ����
		s.push(next++);
	}
	// ���� ���ÿ� ������ �� �������� ������� �׿� ����
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