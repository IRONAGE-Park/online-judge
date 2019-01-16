#include<iostream>
#include<vector>
#define DIGIT 10
#define MAX 10000

using namespace std;

int N; // Data�� ����

template <typename Iterate>
void Print(Iterate begin, Iterate end) { // ����Ʈ�� �����
	for (; begin != end; begin++) {
		cout << *begin << '\n';
	}
}

template <typename Iter>
vector<short> CopyList(Iter begin, Iter end) { // ����Ʈ�� ������
	vector<short> list; // ��ȯ�� ����Ʈ.
	list.reserve(N); // ũ�� �Ҵ�.
	for (; begin != end; begin++)
		list.push_back(*begin);
	return list; // ����Ʈ ��ȯ
}

template <typename Iter>
vector<short> RadixSort(Iter begin, Iter end) { // ��� ����
	vector<short> SortList = CopyList(begin, end); // ����ؼ� ����� ����Ʈ�� ����.
	vector< vector<short> > bucket; // Create Bucket.
	bucket.resize(DIGIT); // 10���� Bucket�� ����.
	for (int i = 0; i < DIGIT; i++)
		bucket[i].reserve(N);
	/* Allocate Bucket Size. */

	for (int div = 1; div <= MAX; div *= 10) {
		for (int i = 0; i < SortList.size(); i++)
			bucket[(SortList[i] / div) % 10].push_back(SortList[i]);
		/* Bucket�� Data�� �й��Ͽ� ���� */
		SortList.clear();
		for (int i = 0; i < DIGIT; i++) {
			for (int j = 0; j < bucket[i].size(); j++)
				SortList.push_back(bucket[i][j]);
			bucket[i].clear();
		}
	}
	return SortList; // ���������� ���ĵ� ����Ʈ ��ȯ.
}

int main() {
	cin >> N;
	vector<short> list;
	list.resize(N);
	for (int i = 0; i < N; i++)
		cin >> list[i];
	/* INPUT DATA */
	list = RadixSort(list.begin(), list.end()); // ��������Ͽ� ���� ��� ����Ʈ�� ����.
	Print(list.begin(), list.end());
	/* OUTPUT DATA */
	return 0;
}