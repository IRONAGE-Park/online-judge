#include<iostream>
#define MAX 1000000
using namespace std;

int list[MAX], N;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int list[]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (list[j] > list[j + 1])
				swap(&list[j], &list[j + 1]);
		}
	}
}

void PrintList(int list[]) {
	for (int i = 0; i < N; i++)
		cout << list[i] << ' ';
	cout << '\n';
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> list[i];
	BubbleSort(list);
	PrintList(list);
	return 0;
}