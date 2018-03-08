/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 1096 - nth Term.cpp
 * Date: 27 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

const int mod = 10007;

struct matrix {
	int row, col, mat[4][4];
	
	matrix() { memset(mat, 0, sizeof mat); }
	matrix operator*(const matrix &m) const {
		matrix r;
		r.row = row;
		r.col = m.col;
		for (int i = 0; i < r.row; i++)
			for (int j = 0; j < r.col; j++) {
				r.mat[i][j] = 0;
				for (int k = 0; k < col; k++)
					r.mat[i][j] = (r.mat[i][j] + mat[i][k] * m.mat[k][j]) % mod;
			}
		return r;
	}
};

matrix identity_matrix;

matrix bigMod(matrix m, int n) {
	if (n == 0) return identity_matrix;
	if (n == 1) return m;
	matrix r = bigMod(m, n/2);
	r = r * r;
	if (n&1) r = m * r;
	return r;
}

int main() {
	identity_matrix.row = identity_matrix.col = 4;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			identity_matrix.mat[i][j] = i == j ? 1 : 0;
	matrix a, b;
	a.row = a.col = b.row = 4;
	b.col = 1;
	a.mat[0][3] = a.mat[1][0] = a.mat[2][1] = a.mat[3][3] = 1;

	int T; scanf("%d", &T);
	for (int cn = 1; cn <= T; cn++) {
		int n; scanf("%d", &n);
		scanf("%d%d%d", &a.mat[0][0], &a.mat[0][2], &b.mat[3][0]);
		if (n <= 2) printf("Case %d: %d\n", cn, 0);
		else {
			matrix r = bigMod(a, n - 2) * b;
			printf("Case %d: %d\n", cn, r.mat[0][0]);
		}
	}
}
