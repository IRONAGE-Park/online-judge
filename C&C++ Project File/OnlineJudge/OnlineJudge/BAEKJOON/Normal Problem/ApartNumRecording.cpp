#include<iostream>
#include<cstdlib>
#define MAX 30

using namespace std;

typedef struct Apt {
	bool check;
	int num;
}Apt;

int compare(const void *a, const void *b)    // �������� �� �Լ� ����
{
	int num1 = *(int *)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int *)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

int easyCompare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int part[MAX*MAX];
int p_num;
Apt Map[MAX][MAX];

void Discover(int i, int j, int pre) {
	if (Map[i][j].check) { // Map[i][j]�� ����Ʈ�� ������
		if (Map[i][j].num == 0) { // �� ����Ʈ�� �Ҵ�� ������ ������
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
	// �Է�. 

	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++) 
			Discover(i, j, 0);

	qsort(part + 1, p_num, sizeof(int), compare); // ������
	cout << p_num << endl;
	for (int i = 1; i <= p_num; i++)
		cout << part[i] << endl;

	return 0;
}