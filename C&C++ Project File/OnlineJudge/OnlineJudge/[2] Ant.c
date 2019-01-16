#include<stdio.h>

enum {
	UP,
	DOWN,
	LEFT,
	RIGHT
};
// UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;

typedef struct State {
	int w; // 가로 진행 방향
	int h; // 세로 진행 방향
}State;

typedef struct Ant { // 개미의 정보에 대한 구조체.
	int x; // x축 위치
	int y; // y축 위치
	State now; // 현재 방향 정보
}Ant;

int main() {
	int width, height, time;
	Ant ant;
	ant.now.w = RIGHT;
	ant.now.h = UP;
	// 기본적으로 오른 쪽 위로 움직이는 중.
	scanf("%d %d", &width, &height);
	scanf("%d %d %d", &ant.x, &ant.y, &time);

	while (time--) { // 시간만큼 반복
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
		// 위치를 본 후 방향 변경 유무 결정.

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
		// 방향 정보와 현재 위치를 토대로 이동.
	}

	printf("%d %d\n", ant.x, ant.y);
	return 0;
}