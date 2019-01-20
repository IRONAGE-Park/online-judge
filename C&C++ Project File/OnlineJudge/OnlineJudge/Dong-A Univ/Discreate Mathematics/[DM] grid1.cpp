#include<iostream>
#include<fstream>
#define EVEN 0

using namespace std;

int Type1_1(int N, int M, int K);
int Type1_2(int N, int M, int K);
int Type1_3(int N, int M, int K);
int Type1_4(int N, int M, int K);
int Type2_1(int N, int M, int K);
int Type2_2(int N, int M, int K);
int Type2_3(int N, int M, int K);
int Type2_4(int N, int M, int K);

int main() {
	ifstream inp("main.inp");
	ofstream out("main.out");
	int testcase;
	inp >> testcase;
	while (testcase--) {
		int N, M, T, S, K, sol;
		inp >> N >> M >> T >> S >> K;
		/* N x M�� ���ڿ���, T = Type, S = �����, K�� �̵��Ÿ� */
		switch (T) {
		case 1: // Type 1��(������� �ݺ� �̵�)
			switch (S) {
			case 1: sol = Type1_1(N, M, K); break;
			case 2: sol = Type1_2(N, M, K); break;
			case 3: sol = Type1_3(N, M, K); break;
			case 4: sol = Type1_4(N, M, K); break;
			}
		case 2: // Type 2��(�������� �ݺ� �̵�)
			switch (S) {
			case 1: sol = Type2_1(N, M, K); break;
			case 2: sol = Type2_2(N, M, K); break;
			case 3: sol = Type2_3(N, M, K); break;
			case 4: sol = Type2_4(N, M, K); break;
		}
		out << sol << '\n';
	}
	return 0;
}

int Type1_1(int N, int M, int K) { // Type 1�� ����� �»�
	int vertical = (K - 1) / M, sol; // �켱 �������� �� ĭ ���������� Ȯ��.
	sol = M * (vertical + 1); // �켱 �� ���� �ִ�ġ��ŭ ������ ��
	if (vertical % 2 == EVEN) {
		/* ¦�� ĭ��ŭ ����������, ���ʿ��� ���������� �̵� */
		sol -= (M - (K % M));
		if (!(K % M)) sol += M; // ������ ó��
	}
	else {
		/* Ȧ�� ĭ��ŭ ����������, �����ʿ��� �������� �̵� */
		sol -= (K - 1) % M; // ��������ŭ ����
	}
	return sol;
}
int Type1_2(int N, int M, int K) { // Type 1�� ����� ���
	int vertical = (K - 1) / M, sol; // �켱 �������� �� ĭ ���������� Ȯ��.
	sol = M * (vertical + 1); // �� ���� ���� ���������� �̵���Ų ��
	if (vertical % 2 == EVEN) {
		/* ¦�� ĭ��ŭ ����������, �����ʿ��� �������� �̵� */
		sol -= (K - 1) % M; // ��������ŭ ����
	}
	else {
		/* Ȧ�� ĭ��ŭ ����������, ���ʿ��� ���������� �̵� */
		sol -= (M - (K % M));
		if (!(K % M)) sol += M; // ������ ó��
	}
	return sol;
}
int Type1_3(int N, int M, int K) { // Type 1�� ����� ����
	int vertical = (K - 1) / M, sol = N * M; // �켱 �������� �� ĭ �ö󰬴��� Ȯ��.
	sol -= M * vertical; // �켱 �� ���� �ִ�ġ��ŭ ���� ��
	if (vertical % 2 == EVEN) {
		/* ¦�� ĭ��ŭ �ö�����, �����ʿ��� �������� �̵� */
		sol -= (K - 1) % M; // ��������ŭ ����
	}
	else {
		/* Ȧ�� ĭ��ŭ �ö�����, ���ʿ��� ���������� �̵� */
		sol -= (M - (K % M));
		if (!(K % M)) sol += M; // ������ ó��
	}
	return sol;
}
int Type1_4(int N, int M, int K) { // Type 1�� ����� ����
	int vertical = (K - 1) / M, sol = N * M; // �켱 �������� �� ĭ ���������� Ȯ��.
	sol -= M * vertical; // �� ���� ���� ���������� �̵���Ų ��
	if (vertical % 2 == EVEN) {
		/* ¦�� ĭ��ŭ �ö�����, ���ʿ��� ���������� �̵� */
		sol -= (M - (K % M));
		if (!(K % M)) sol += M; // ������ ó��
	}
	else {
		/* Ȧ�� ĭ��ŭ �ö�����, �����ʿ��� �������� �̵� */
		sol -= (K - 1) % M; // ��������ŭ ����
	}
	return sol;
}

int Type2_1(int N, int M, int K) { // Type 2�� ����� �»�
	int pararel = (K - 1) / N, sol = 1; // �켱 �������� �� ĭ ������ Ȯ��.
	sol += pararel; // �̵��� �Ÿ���ŭ ������ ��
	if (pararel % 2 == EVEN) {
		/* ¦�� ĭ��ŭ ������, ���ʿ��� �Ʒ������� �̵� */
		sol += ((K - 1) % N) * M;
	}
	else {
		/* Ȧ�� ĭ��ŭ ������, �Ʒ��ʿ��� �������� �̵� */
		sol += ((N - 1) * M);
		sol -= ((K - 1) % N) * M;
	}
	return sol;
}
int Type2_2(int N, int M, int K) { // Type 2�� ����� ���
	int pararel = (K - 1) / N, sol = M; // �켱 �������� �� ĭ ������ Ȯ��.
	sol -= pararel; // �̵��� �Ÿ���ŭ ���� ��
	if (pararel % 2 == EVEN) {
		/* ¦�� ĭ��ŭ ������, ���ʿ��� �Ʒ������� �̵� */
		sol += ((K - 1) % N) * M;
	}
	else {
		/* Ȧ�� ĭ��ŭ ������, �Ʒ��ʿ��� �������� �̵� */
		sol += ((N - 1) * M);
		sol -= ((K - 1) % N) * M;
	}
	return sol;
}
int Type2_3(int N, int M, int K) { // Type 2�� ����� ����
	int pararel = (K - 1) / N, sol = N * M; // �켱 �������� �� ĭ ������ Ȯ��.
	sol -= pararel; // �̵��� �Ÿ���ŭ ���� ��
	if (pararel % 2 == EVEN) {
		/* ¦�� ĭ��ŭ ������, �Ʒ��ʿ��� �������� �̵� */
		sol -= ((K - 1) % N) * M;
	}
	else {
		/* Ȧ�� ĭ��ŭ ������, ���ʿ��� �Ʒ������� �̵� */
		sol -= ((N - 1) * M);
		sol += ((K - 1) % N) * M;
	}
	return sol;
}
int Type2_4(int N, int M, int K) { // Type 2�� ����� ����
	int pararel = (K - 1) / N, sol = ((N - 1) * M) + 1; // �켱 �������� �� ĭ ������ Ȯ��.
	sol += pararel; // �̵��� �Ÿ���ŭ ���� ��
	if (pararel % 2 == EVEN) {
		/* ¦�� ĭ��ŭ ������, �Ʒ��ʿ��� �������� �̵� */
		sol -= ((K - 1) % N) * M;
	}
	else {
		/* Ȧ�� ĭ��ŭ ������, ���ʿ��� �Ʒ������� �̵� */
		sol -= ((N - 1) * M);
		sol += ((K - 1) % N) * M;
	}
	return sol;
}