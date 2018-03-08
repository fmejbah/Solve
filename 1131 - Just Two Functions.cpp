/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 1131 - Just Two Functions.cpp
 * Date: 27 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

int mod;

struct matrix {
	int row, col, mat[6][6];
	matrix(int r, int c) {
		row = r, col = c;
		memset(mat, 0, sizeof mat);
	}
	matrix operator*(const matrix &m) const {
		matrix r(row, m.col);
		for (int i = 0; i < r.row; i++)
			for (int j = 0; j < r.col; j++)
				for (int k = 0; k < col; k++)
					r.mat[i][j] = (r.mat[i][j] + mat[i][k] * m.mat[k][j]) % mod;
		return r;
	}
	void print() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				cout << mat[i][j] << ' ';
			puts("");
		}
	}
}identity_matrix(6, 6);

matrix bigMod(matrix m, int n) {
	if (n == 0) return identity_matrix;
	if (n == 1) return m;
	matrix r = bigMod(m, n/2);
	r = r * r;
	if (n&1) r = m * r;
	return r;
}

int main() {
	for (int i = 0; i < 6; i++)
		identity_matrix.mat[i][i] = 1;
	matrix a(6,6), b(6, 1);
	a.mat[1][0] = a.mat[2][1] = a.mat[4][3] = a.mat[5][4] = 1; 
	int T; scanf("%d", &T);
	for (int cn = 1; cn <= T; cn++) {
		scanf("%d%d%d", &a.mat[0][0], &a.mat[0][1], &a.mat[0][5]); 
		scanf("%d%d%d", &a.mat[3][3], &a.mat[3][4], &a.mat[3][2]); 
		for (int i = 2; i >= 0; i--)
			scanf("%d", &b.mat[i][0]);
		for (int i = 5; i >= 3; i--)
			scanf("%d", &b.mat[i][0]);
		scanf("%d", &mod);
		int q; scanf("%d", &q);
		printf("Case %d:\n", cn);
		while (q--) {
			int n; scanf("%d", &n);
			if (n <= 2) printf("%d %d\n", b.mat[2 - n][0], b.mat[5 - n][0]);
			else {
				matrix r = bigMod(a, n - 2) * b;
				printf("%d %d\n", r.mat[0][0], r.mat[3][0]);
			}
		}
	}
}
