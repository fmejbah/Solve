#include <bits/stdc++.h>

using namespace std;

struct matrix {
  int row, col, mat[31][31];
  matrix operator+(const matrix &a) const {
    matrix r;
    r.row = row;
    r.col = col;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        r.mat[i][j] = (mat[i][j] + a.mat[i][j]) % 10;
      }
    }
    return r;
  }
  matrix operator*(const matrix &a) const {
    matrix r;
    r.row = row;
    r.col = a.col;
    for (int i = 0; i < r.row; i++) {
      for (int j = 0; j < r.col; j++) {
        r.mat[i][j] = 0;
        for (int k = 0; k < col; k++) {
          r.mat[i][j] = (r.mat[i][j] + mat[i][k] * a.mat[k][j]) % 10;
        }
      }
    }
    return r;
  }
}identity_matrix;

matrix bigSum(matrix a, int n) {
  if (n == 1) {
    return identity_matrix;
  }
  matrix x = bigSum(a * a, n / 2);
  x = x * (a + identity_matrix);
  if (n&1) {
    x = identity_matrix + a * x;
  }
  return x;
}

int main() {
  memset(identity_matrix.mat, 0, sizeof identity_matrix.mat);
  for(int i = 0; i < 31; i++) {
    identity_matrix.mat[i][i] = 1;
  }
  int T, n, k;
  matrix a;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &n, &k);
    a.row = a.col = n;
    identity_matrix.row = identity_matrix.col = n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &a.mat[i][j]);
        a.mat[i][j] %= 10;
      }
    }
    a = a * bigSum(a, k);
    printf("Case %d:\n", cn);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d", a.mat[i][j]);
      }
      puts("");
    }
  }
}
