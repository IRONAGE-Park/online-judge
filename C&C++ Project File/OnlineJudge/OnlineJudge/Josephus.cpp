#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

typedef struct Node {
	int num;
	struct Node *next;
}Node;

Node *CreateNode(int num) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->num = num;
	return newNode;
}
Node *CreateList(int num, int n) {
	if (num >= n) {
		Node *newNode = CreateNode(n);
		newNode->next = CreateList(num, n + 1);
		return newNode;
	}
	else return NULL;
}
void LastContact(Node *List) {
	Node *ptr = List;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = List;
}

void Delete(Node *ptr) {
	Node *p = ptr->next;
	ptr->next = p->next;
	cout << p->num << ", ";
	free(p);
}

void JosephusAlgorithm(Node *List, int n, int m) {
	cout << "<";
	Node *ptr = List, *pre = List;
	for (int i = 0; i < n - 2; i++) pre = pre->next;
	ptr = pre;
	while (n > 2) {
		for (int i = 0; i < m - 1; i++)	pre = pre->next;
		ptr = pre->next;
		Delete(ptr);
		ptr = pre;
		n--;
	}
	if (n == 1) {
		cout << ptr->num << ">";
	}
	else {
		while (m--)
			pre = pre->next;
		ptr = pre->next;
		cout << ptr->num << ", " << pre->num << ">";
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	Node *List = CreateList(n, 1);
	LastContact(List);
	JosephusAlgorithm(List, n, m);
	return 0;
}