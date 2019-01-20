#include<iostream>
#include<vector>
#define DIGIT 10
#define MAX 10000

using namespace std;

int N; // Data의 갯수

template <typename Iterate>
void Print(Iterate begin, Iterate end) { // 리스트를 출력함
	for (; begin != end; begin++) {
		cout << *begin << '\n';
	}
}

template <typename Iter>
vector<short> CopyList(Iter begin, Iter end) { // 리스트를 복사함
	vector<short> list; // 반환될 리스트.
	list.reserve(N); // 크기 할당.
	for (; begin != end; begin++)
		list.push_back(*begin);
	return list; // 리스트 반환
}

template <typename Iter>
vector<short> RadixSort(Iter begin, Iter end) { // 기수 정렬
	vector<short> SortList = CopyList(begin, end); // 계속해서 변경될 리스트를 저장.
	vector< vector<short> > bucket; // Create Bucket.
	bucket.resize(DIGIT); // 10개의 Bucket을 만듬.
	for (int i = 0; i < DIGIT; i++)
		bucket[i].reserve(N);
	/* Allocate Bucket Size. */

	for (int div = 1; div <= MAX; div *= 10) {
		for (int i = 0; i < SortList.size(); i++)
			bucket[(SortList[i] / div) % 10].push_back(SortList[i]);
		/* Bucket에 Data를 분배하여 담음 */
		SortList.clear();
		for (int i = 0; i < DIGIT; i++) {
			for (int j = 0; j < bucket[i].size(); j++)
				SortList.push_back(bucket[i][j]);
			bucket[i].clear();
		}
	}
	return SortList; // 최종적으로 정렬된 리스트 반환.
}

int main() {
	cin >> N;
	vector<short> list;
	list.resize(N);
	for (int i = 0; i < N; i++)
		cin >> list[i];
	/* INPUT DATA */
	list = RadixSort(list.begin(), list.end()); // 기수정렬하여 나온 결과 리스트를 저장.
	Print(list.begin(), list.end());
	/* OUTPUT DATA */
	return 0;
}