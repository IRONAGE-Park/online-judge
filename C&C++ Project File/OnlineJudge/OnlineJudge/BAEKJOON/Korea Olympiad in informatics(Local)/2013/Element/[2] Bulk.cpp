#include<iostream>
using namespace std;

typedef struct Person {
	int weight;
	int height;
	int cnt;
}Person;

int main() {
	Person person[50];
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> person[i].weight >> person[i].height;
		person[i].cnt = 1;
	} // input data.
		
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			if (person[i].weight < person[j].weight && person[i].height < person[j].height)
				person[i].cnt++;
	} // 
	
	for (int i = 0; i < num; i++) cout << person[i].cnt << " ";
	// output data.
	return 0;
}