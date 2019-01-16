#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream inp("dish.inp");
	ofstream out("dish.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int len, height = 0;
		char c, before = '\0'; // before�� ��� ù ����� ���� �⺻ ������ �ʱ�ȭ
		inp >> len;
		while (len--) { // ó�� �־��� ���̸�ŭ �ݺ� �Է�
			inp >> c; // ����(�׸�)�� �Է� �ް�,
			if (c != before) height += 10; // ���� �׸��� �Է� ���� �׸��� �ٸ��� ���̰� 10 �߰�.
			else height += 5; // ���� ��� ���� 5 �߰�
			before = c; // ���� �׸�(��ȣ)�� ���� ����
		}
		out << height << '\n'; // ���� �� ���
	}
	inp.close();
	out.close();
	return 0;
}