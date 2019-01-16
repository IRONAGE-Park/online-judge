#include <stdio.h>

int main(void) {
	int n, result, num;
	/*
	n은 배달할 kg, result는 봉투의 갯수,
	num = 5kg봉지로 모두 담은 뒤 나머지.
	*/
	scanf("%d", &n);
	int k = 0; // 3kg짜리 봉지를 기본적으로 몇 개 가져가느냐.

	while (n >= 3) {
		/*
		이 반복 문을 돌리다 보면, 어느 순간 else문에 의해서
		n이 3 이하로 내려가는 경우가 생김, 그렇게 된다는 것은 3개짜리 봉지를
		아무리 추가해도 이 무게 n은 담아서 배달할 수 없다는 뜻이 됨.
		*/
		result = k;
		result += n / 5;

		num = n % 5;
		if (num % 3 == 0) {
			result += num / 3;
			break;
		}
		else {
			k++; // 3kg짜리 봉투 하나를 추가해서 계산.
			n -= 3; // 배달할 kg에서, 3kg 봉투를 기본적으로 하나 더 사용하기 때문에 3kg 뺌.
		}
	}
	if (n >= 3) { // n이 3보다 큰 상태에서 무사히 반복 문을 빠져나왔을 경우 => 배달 가능.
		printf("%d\n", result);
	}
	else { // n이 3보다 작은 상태에서 반복문 조건에 의해 빠져나왔을 경우 => 배달 불가능.
		printf("-1\n");
	}
	return 0;
}