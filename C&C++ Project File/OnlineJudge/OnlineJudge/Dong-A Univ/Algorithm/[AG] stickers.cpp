#include<iostream>
#include<fstream>

using namespace std;

int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	ifstream inp("stickers.inp");
	ofstream out("stickers.out");

	int testcase;
	inp >> testcase;

	while (testcase--) {
		int sticker[2][100000] = { 0 }, num;
		inp >> num;
		for (int i = 0; i < 2; i++) for (int j = 0; j < num; j++) inp >> sticker[i][j];
		sticker[0][1] = sticker[1][0] + sticker[0][1], sticker[1][1] = sticker[0][0] + sticker[1][1];
		// �ʱ� �� ����
		for (int i = 2; i < num; i++) {
			sticker[0][i] += MAX(sticker[1][i - 2], sticker[1][i - 1]); // ���� ����
			sticker[1][i] += MAX(sticker[0][i - 2], sticker[0][i - 1]); // �Ʒ� ����
		}
		out << MAX(sticker[0][num - 1], sticker[1][num - 1]) << '\n';
	}
	inp.close();
	out.close();
	return 0;
}