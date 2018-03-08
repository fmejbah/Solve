#include <bits/stdc++.h>

using namespace std;

#define MAX 1123

typedef long long int LL;

const int MOD = 1e9 + 7;

int A[MAX][MAX], D[MAX];

int mod(LL a) {
  a %= MOD;
  if (a < 0) {
    a += MOD;
  }
  return a;
}

int nCr(int n, int r) {
  if (n == r || r == 0) {
    return 1;
  }
  if (r == 1) {
    return n;
  }
  if (A[n][r] < 0) {
    A[n][r] = mod(nCr(n - 1, r - 1) + nCr(n - 1, r));
  }
  return A[n][r];
}

int main() {
  int T, n, m, k, ans;
  D[0] = D[2] = 1;
  for (int i = 3; i < 1001; i++) {
    D[i] = mod((i - 1LL) * (D[i - 1] + D[i - 2]));
  }
  memset(A, -1, sizeof A);
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d%d", &n, &m, &k);
    ans = 0;
    for (int i = 0; i <= n - m; i++) {
      ans = mod(ans + mod(nCr(n - m, i) * 1LL * D[n - k - i]));
    }
    ans = mod(ans * 1LL * nCr(m, k));
    printf("Case %d: %d\n", cn, ans);
  }
}
