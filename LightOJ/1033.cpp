#include <bits/stdc++.h>

using namespace std;

const int MAX = 1123;

int T, A[MAX][MAX], n;
char s[MAX];

int f(int i, int j) {
  if (i >= j) {
    return 0;
  }
  if (A[i][j] == -1) {
    if (s[i] == s[j]) {
      A[i][j] = f(i + 1, j - 1);
    } else {
      A[i][j] = 1 + min(f(i + 1, j), f(i, j - 1));
    }
  }
  return A[i][j];
}

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%s", s);
    n = strlen(s);
    memset(A, -1, sizeof A);
    printf("Case %d: %d\n", cn, f(0, n - 1));
  }
}
