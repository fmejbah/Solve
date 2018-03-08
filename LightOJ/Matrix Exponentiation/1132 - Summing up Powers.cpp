/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 1132 - Summing up Powers.cpp
 * Date: 27 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

const long long int mod = 1ll << 32;

struct matrix {
	int row, col;
	unsigned long long int mat[55][55];
	matrix() { memset(mat, 0, sizeof mat); }
	matrix(int r, int c) {
		row = r, col = c;
		memset(mat, 0, sizeof mat);
	}
	matrix operator*(const matrix &m) const {
		matrix r(row, m.col);
		for (int i = 0; i < r.row; i++)
			for (int j = 0; j < r.col; j++)
				for (int k = 0; k < col; k++)
					r.mat[i][j] = (r.mat[i][j] + (mat[i][k] * m.mat[k][j]) % mod) % mod;
		return r;
	}
	void print() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
				cout << mat[i][j] << ' ';
			puts("");
		}
	}
	void identityMatrix(int k) {
		row = col = k;
		for (int i = 0; i < row; i++)
			mat[i][i] =  1;
	}
}identity_matrix;

matrix bigMod(matrix m, long long int n) {
	if (n == 0) return identity_matrix;
	if (n == 1) return m;
	matrix r = bigMod(m, n/2);
	r = r * r;
	if (n&1) r = m * r;
	return r;
}

long long int A[51][51];

long long int nCr(int n, int r) {
	if (r == 0 || n == r ) return 1;
	if (A[n][r] != -1) return A[n][r];
	return A[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % mod;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	memset(A, -1, sizeof A);
	int T; scanf("%d", &T);
	for (int cn = 1; cn <= T; cn++) {
		long long int n, k;
		scanf("%lld%lld", &n, &k);
		identity_matrix.identityMatrix(k);
		//cout << "I:\n"; identity_matrix.print();
		matrix a(k + 2, k + 2), b(k + 2, 1);
		for (int i = 0; i < b.row; i++)
			b.mat[i][0] = 1;
		a.mat[0][0] = 1;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j < a.col; j++)
				a.mat[i][j] = nCr(k, j - 1);
		for (int i = 2; i < a.row; i++)
			for (int j = i; j < a.col; j++)
				a.mat[i][j] = nCr(k - i + 1, j - i);
		//cout << "a:\n"; a.print();
		//cout << "b:\n"; b.print();
		matrix r = bigMod(a, n - 1) * b;
		//cout << "r:\n"; r.print();
		printf("Case %d: %lld\n", cn, r.mat[0][0]);
	}
}
