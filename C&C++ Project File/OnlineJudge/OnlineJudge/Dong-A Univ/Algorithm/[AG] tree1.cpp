#include<iostream>
#include<fstream>
#include<string>
#define DECIMAL 10

using namespace std;

int cnt, i;
string answer;

typedef struct Node {
	string name;
	bool rcheck;
	struct Node *left;
	struct Node *right;
}Node;

Node *itos(Node *root, int n) {
	root->name = "r";
	if (n == 0)
		root->name += "0";
	else {
		while (n) {
			char *num = new char[2];
			num[0] = (n % DECIMAL) + 48;
			num[1] = '\0';
			root->name.insert(1, num);
			n /= DECIMAL;
		}
	}
	return root;
}

void preorder(Node *root) { // 전위순회
	if (root) {
		if (root->rcheck) { // 이름 부여
			root = itos(root, cnt);
			cnt++;
		}
		answer += root->name + '\n';
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node *root) { // 중위순회
	if (root) {
		inorder(root->left);
		answer += root->name + '\n';
		inorder(root->right);
	}
}

Node *insert(Node *root, string str) {
	Node *newLeft = new Node;
	newLeft->rcheck = false;
	newLeft->left = NULL, newLeft->right = NULL;
	root->rcheck = true; // 부모 노드라면 r 표시

	if (i == 0 && str[i] == '(') i++; // 추가
	while (str[i] == ')' || str[i] == ' ') i++;
	if (root->left == NULL) { // 루트 노드의 왼쪽이 비었을 경우
		if (str[i] == '(') { // 괄호(자식노드 추가)
			i++;
			newLeft = insert(newLeft, str);
			root->left = newLeft;
		}
		else if (str[i] >= 48) {
			for (; str[i] != ' '; i++) { // 추가
				newLeft->name += str[i];
			}
			root->left = newLeft;
		}
	}

	while (str[i] == ')' || str[i] == ' ') i++;
	Node *newRight = new Node;
	newRight->rcheck = false;
	newRight->left = NULL, newRight->right = NULL;
	if (root->right == NULL) { // 루트노드의 오른쪽이 비었을 경우
		if (str[i] == '(') { // 괄호(자식노드 추가)
			i++;
			newRight = insert(newRight, str);
			root->right = newRight;
		}
		else if (str[i] >= 48) {
			for (; str[i] != ' '; i++) { // 추가
				newRight->name += str[i];
			}
			root->right = newRight;
		}
	}
	return root;
}

int main() {
	ifstream inp("tree1.inp");
	ofstream out("tree1.out");
	// ifstream inp("input.txt");
	// ofstream out("output.txt");
	
	int testcase;
	inp >> testcase;
	inp.get();
	while(testcase--) {
		cnt = 0, i = 0;
		string str;
		answer = "";
		getline(inp, str);
		out << str << '\n';
		Node *root = new Node;
		root->rcheck = false;
		root->left = NULL, root->right = NULL;  // 루트 초기화
		root = insert(root, str);
		answer += "Preorder\n";
		preorder(root);
		answer += "Inorder\n";
		inorder(root);
		out << answer;
	}
	inp.close();
	out.close();
	return 0;
}