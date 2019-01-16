#include<stdio.h>

enum {
	UP,
	DOWN,
	LEFT,
	RIGHT
};
// UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;

typedef struct State {
	int w; // ���� ���� ����
	int h; // ���� ���� ����
}State;

typedef struct Ant { // ������ ������ ���� ����ü.
	int x; // x�� ��ġ
	int y; // y�� ��ġ
	State now; // ���� ���� ����
}Ant;

int main() {
	int width, height, time;
	Ant ant;
	ant.now.w = RIGHT;
	ant.now.h = UP;
	// �⺻������ ���� �� ���� �����̴� ��.
	scanf("%d %d", &width, &height);
	scanf("%d %d %d", &ant.x, &ant.y, &time);

	while (time--) { // �ð���ŭ �ݺ�
		if (ant.now.w == RIGHT) {
			if (ant.x == width) {
				ant.now.w = LEFT;
			}
		}
		else {
			if (ant.x == 0) {
				ant.now.w = RIGHT;
			}
		}
		if (ant.now.h == UP) {
			if (ant.y == height) {
				ant.now.h = DOWN;
			}
		}
		else {
			if (ant.y == 0) {
				ant.now.h = UP;
			}
		}
		// ��ġ�� �� �� ���� ���� ���� ����.

		if (ant.now.w == RIGHT) {
			ant.x += 1;
		}
		else {
			ant.x -= 1;
		}
		if (ant.now.h == UP) {
			ant.y += 1;
		}
		else {
			ant.y -= 1;
		}
		// ���� ������ ���� ��ġ�� ���� �̵�.
	}

	printf("%d %d\n", ant.x, ant.y);
	return 0;
}