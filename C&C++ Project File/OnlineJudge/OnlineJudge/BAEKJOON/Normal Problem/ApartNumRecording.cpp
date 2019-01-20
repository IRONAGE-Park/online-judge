#include<iostream>
#include<cstdlib>
#define MAX 30

using namespace std;

typedef struct Apt {
	bool check;
	int num;
}Apt;

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

int easyCompare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int part[MAX*MAX];
int p_num;
Apt Map[MAX][MAX];

void Discover(int i, int j, int pre) {
	if (Map[i][j].check) { // Map[i][j]에 아파트가 있으면
		if (Map[i][j].num == 0) { // 그 아파트에 할당된 단지가 없으면
			if (pre == 0) {
				p_num++;
				part[p_num]++;
				Map[i][j].num = p_num;
			}
			else {
				Map[i][j].num = pre;
				part[pre]++;
			}
			Discover(i - 1, j, Map[i][j].num);
			Discover(i, j - 1, Map[i][j].num);
			Discover(i + 1, j, Map[i][j].num);
			Discover(i, j + 1, Map[i][j].num);
		}
	}
}

int main() {
	char at;
	int size;
	cin >> size;

	for (int i = 1; i <= size; i++) 
		for (int j = 1; j <= size; j++) 
			cin >> at, Map[i][j].check = (bool)(at - 48);
	// 입력. 

	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++) 
			Discover(i, j, 0);

	qsort(part + 1, p_num, sizeof(int), compare); // 퀵정렬
	cout << p_num << endl;
	for (int i = 1; i <= p_num; i++)
		cout << part[i] << endl;

	return 0;
}