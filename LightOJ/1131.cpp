#include <bits/stdc++.h>

using namespace std;

int mod;

struct matrix {
  int row, col, mat[6][6];
  matrix operator*(const matrix &a) const {
    matrix r;
    r.row = row;
    r.col = a.col;
    for (int i = 0; i < r.row; i++) {
      for (int j = 0; j < r.col; j++) {
        r.mat[i][j] = 0;
        for (int k = 0; k < col; k++) {
          r.mat[i][j] = (r.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
        }
      }
    }
    return r;
  }
}identity_matrix;

matrix bigMod(matrix a, int n) {
  if (n == 0) {
    return identity_matrix;
  }
  matrix x = bigMod(a, n / 2);
  x = x * x;
  if (n&1) {
    x = x * a;
  }
  return x;
}

int main() {
  int T, q, n;
  identity_matrix.row = 6;
  identity_matrix.col = 6;
  memset(identity_matrix.mat, 0, sizeof identity_matrix.mat);
  for (int i = 0; i < 6; i++) {
    identity_matrix.mat[i][i] = 1;
  }
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    matrix b, a;
    a.row = 6; a.col = 1;
    memset(a.mat, 0, sizeof a.mat);
    b.row = 6; b.col = 6;
    memset(b.mat, 0, sizeof b.mat);
    scanf("%d%d%d", &b.mat[0][0], &b.mat[0][1], &b.mat[0][5]);
    scanf("%d%d%d", &b.mat[3][3], &b.mat[3][4], &b.mat[3][2]);
    scanf("%d%d%d", &a.mat[2][0], &a.mat[1][0], &a.mat[0][0]);
    scanf("%d%d%d", &a.mat[5][0], &a.mat[4][0], &a.mat[3][0]);
    b.mat[1][0] = b.mat[2][1] = b.mat[4][3] = b.mat[5][4] = 1;
    scanf("%d%d", &mod, &q);
    b.mat[0][0] %= mod; b.mat[0][1] %= mod; b.mat[0][5] %= mod;
    b.mat[3][3] %= mod; b.mat[3][4] %= mod; b.mat[3][2] %= mod;
    for (int i = 0; i < 6; i++) {
      a.mat[i][0] %= mod;
    }
    printf("Case %d:\n", cn);
    while (q--) {
      scanf("%d", &n);
      if (n > 2) {
        matrix r = bigMod(b, n - 2) * a;
        printf("%d %d\n", r.mat[0][0], r.mat[3][0]);
      } else if(n == 0) {
        printf("%d %d\n", a.mat[2][0], a.mat[5][0]);
      } else if(n == 1) {
        printf("%d %d\n", a.mat[1][0], a.mat[4][0]);
      } else if(n == 2) {
        printf("%d %d\n", a.mat[0][0], a.mat[3][0]);
      }
    }
  }
}
