#include <bits/stdc++.h>

using namespace std;

const int mod = 10007;

struct matrix {
  int row, col, mat[3][3];
  matrix(int r, int c) {
    row = r;
    col = c;
    memset(mat, 0, sizeof mat);
  }
  matrix operator*(const matrix& a) const {
    matrix r = matrix(row, a.col);
    for (int i = 0; i < r.row; i++) {
      for (int j = 0; j < r.col; j++) {
        for (int k = 0; k < col; k++) {
          r.mat[i][j] = (r.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
        }
      }
    }
    return r;
  }
}identity_matrix = matrix(3, 3);

matrix bigMod(matrix a, int n) {
  if (n == 0) {
    return identity_matrix;
  }
  matrix x = bigMod(a, n / 2);
  x = x * x;
  if (n&1) {
    x = a * x;
  }
  return x;
}

int main() {
  int T, n;
  matrix a = matrix(3, 1);
  matrix b = matrix(3, 3);
  a.mat[0][0] = 5;
  a.mat[1][0] = 2;
  a.mat[2][0] = 1;
  b.mat[0][0] = 2;
  b.mat[0][2] = b.mat[1][0] = b.mat[2][1] = 1;
  for(int i = 0; i < 3; i++) {
    identity_matrix.mat[i][i] = 1;
  }
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &n);
    if(n < 3) {
      printf("Case %d: %d\n", cn, n);
    } else {
      matrix r = bigMod(b, n - 3) * a;
      printf("Case %d: %d\n", cn, r.mat[0][0]);
    }
  }
}
