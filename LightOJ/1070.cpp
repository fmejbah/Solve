#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

struct matrix {
  int row, col;
  ull mat[2][2];
  matrix operator*(const matrix& a) const {
    matrix r;
    r.row = row;
    r.col = a.col;
    for (int i = 0; i < r.row; i++) {
      for (int j = 0; j < r.col; j++) {
        r.mat[i][j] = 0;
        for (int k = 0; k < col; k++) {
          r.mat[i][j] += mat[i][k] * a.mat[k][j];
        }
      }
    }
    return r;
  }
}identity_matrix;

int t, p, q, n;

matrix power(matrix a, int n) {
  if (n == 0) {
    return identity_matrix;
  }
  matrix m = power(a, n / 2);
  m = m * m;
  if (n&1) {
    m = a * m;
  }
  return m;
}

int main() {
  // indentity matrix
  identity_matrix.row = 2; identity_matrix.col = 2;
  identity_matrix.mat[0][0] = 1; identity_matrix.mat[0][1] = 0;
  identity_matrix.mat[1][0] = 0; identity_matrix.mat[1][1] = 1;

  scanf("%d", &t);
  for (int cn = 1; cn <= t; cn++) {
    scanf("%d%d%d", &p, &q, &n);
    // initialize matrix
    matrix a; a.row = a.col = 2;
    a.mat[0][0] = p; a.mat[0][1] = -1;
    a.mat[1][0] = q; a.mat[1][1] = 0;
    // clculate a^n
    matrix r = power(a, n);
    printf("Case %d: %llu\n", cn, r.mat[0][0] + r.mat[1][1]);
  }
}
