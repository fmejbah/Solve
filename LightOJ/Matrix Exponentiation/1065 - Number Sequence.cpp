/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 1065 - Number Sequence.cpp
 * Date: 27 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

int mod, A[] = {1, 10, 100, 1000, 10000};

struct matrix {
	int row, col, mat[2][2];
	matrix operator*(const matrix &a) const {
		matrix r;
		r.row = row;
		r.col = a.col;
		for (int i = 0; i < r.row; i++)
			for (int j = 0; j < r.col; j++) {
				r.mat[i][j] = 0;
				for (int k = 0; k < col; k++) {
					r.mat[i][j] += mat[i][k] * a.mat[k][j];
					r.mat[i][j] %= mod;
				}
			}
		return r;
	}
	void print() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				cout << mat[i][j] << ' ';
			puts("");
		}
	}
};

matrix identity_matrix;

matrix bigMod(matrix m, int n) {
	if (n == 0) return identity_matrix;
	if (n == 1) return m;
	matrix r = bigMod(m, n/2);
	r = r * r;
	if (n&1) r = r * m;
	return r;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	identity_matrix.row = identity_matrix.col = 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			identity_matrix.mat[i][j] = i == j ? 1 : 0;
	matrix a, b;
	a.row = a.col = 2;
	a.mat[0][0] = a.mat[0][1] = a.mat[1][0] = 1;
	a.mat[1][1] = 0;
	b.row = 2, b.col = 1;
	int T; scanf("%d", &T);
	for (int cn = 1; cn <= T; cn++) {
		int n, m;
		scanf("%d%d%d%d", &b.mat[1][0], &b.mat[0][0], &n, &m);
		mod = A[m];
		if (n == 0) printf("Case %d: %d\n", cn, b.mat[1][0] % mod);
		//else if (n == 1) printf("Case %d: %d\n", cn, b.mat[0][0] % mod);
		else {
			matrix r = bigMod(a, n - 1);
			r = r * b;
			printf("Case %d: %d\n", cn, r.mat[0][0]);
		}
	}
}
