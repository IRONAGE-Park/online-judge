#include<cstdio>

char map[200][200];
int cnt;

char sameCheck(int sx, int sy, int n, int m) { // -1 �̸� ������ �ٸ�
	for (int i = sy; i < m; i++) {
		for (int j = sx; j < n; j++) {
			if (map[sy][sx] != map[i][j]) return -1;
		}
	}
	return map[sy][sx];
}

int divide(int x) {
	if (x % 2 == 0) {
		return x / 2;
	}
	else return (x / 2) + 1;
}

void cond(FILE *out, int sx, int sy, int n, int m) { // ����
	if (sameCheck(sx, sy, n, m) != -1) { // ���ΰ� ��� ������
		fprintf(out, "%c", sameCheck(sx, sy, n, m));
		cnt++;
		if (cnt % 50 == 0) fprintf(out, "\n");
	}
	else { // ���ΰ� �ٸ���
		fprintf(out, "D");
		cnt++;
		if (cnt % 50 == 0) fprintf(out, "\n"); // 50���� ������ ����

		if (n - sx == 1) { // ���� �� ��
			cond(out, sx, sy, divide(n + sx), divide(m + sy)); // ���� ���
			cond(out, sx, divide(m + sy), divide(n + sx), m); // ���� �ϴ�
		}
		else if (m - sy == 1) { // ���� �� ��
			cond(out, sx, sy, divide(n + sx), divide(m + sy)); // ���� ���
			cond(out, divide(n + sx), sy, n, divide(m + sy)); // ������ ���
		}
		else {
			cond(out, sx, sy, divide(n + sx), divide(m + sy)); // ���� ���
			cond(out, divide(n + sx), sy, n, divide(m + sy)); // ������ ���
			cond(out, sx, divide(m + sy), divide(n + sx), m); // ���� �ϴ�
			cond(out, divide(n + sx), divide(m + sy), n, m); // ������ �ϴ�
		}
	}
}

void div(FILE *inp, int sx, int sy, int n, int m) {
	char f;
	fscanf(inp, "%c", &f);
	if (f == '\n') fscanf(inp, "%c", &f); // ���๮�ڰ� ���� �ѱ�

	if (f == 'D') {
		if (n - sx == 1) { // ���� �� ��
			div(inp, sx, sy, divide(n + sx), divide(m + sy)); // ���� ���
			div(inp, sx, divide(m + sy), divide(n + sx), m); // ���� �ϴ�
		}
		else if (m - sy == 1) { // ���� �� ��
			div(inp, sx, sy, divide(n + sx), divide(m + sy)); // ���� ���
			div(inp, divide(n + sx), sy, n, divide(m + sy)); // ������ ���
		}
		else {
			div(inp, sx, sy, divide(n + sx), divide(m + sy)); // ���� ���
			div(inp, divide(n + sx), sy, n, divide(m + sy)); // ������ ���
			div(inp, sx, divide(m + sy), divide(n + sx), m); // ���� �ϴ�
			div(inp, divide(n + sx), divide(m + sy), n, m); // ������ �ϴ�
		}
	}
	else {
		for (int i = sy; i < m; i++) {
			for (int j = sx; j < n; j++) {
				map[i][j] = f;
			}
		}
	}
}

int main() {
	FILE *inp = fopen("bitmap.inp", "r");
	FILE *out = fopen("bitmap.out", "w");
	while (1) {
		char form, c;
		int m, n;
		cnt = 0;
		fscanf(inp, "%c %d %d\n", &form, &m, &n);
		if (form == '#') break;
		else if (form == 'B') { // B => D
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					fscanf(inp, "%c", &c);
					if (c == '\n') { // ���� 50��° ���ڿ����� check�� ���๮���̸� ����
						j--;
						continue;
					}
					else map[i][j] = c;
				}
			} // bitmap�� �Է�
			fprintf(out, "D%4d%4d\n", m, n);
			cond(out, 0, 0, n, m);
			fprintf(out, "\n");
			fscanf(inp, "%c", &c); // ������ ���๮�� ó��
		}
		else { // D => B
			fprintf(out, "B%4d%4d\n", m, n);
			div(inp, 0, 0, n, m);
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					fprintf(out, "%c", map[i][j]);
					cnt++;
					if (cnt % 50 == 0) fprintf(out, "\n");
				}
			}
			if (cnt % 50 != 0) fprintf(out, "\n");
			fscanf(inp, "%c", &c); // ������ ���๮�� ó��
		}
	}
	fclose(inp);
	fclose(out);
	return 0;
}