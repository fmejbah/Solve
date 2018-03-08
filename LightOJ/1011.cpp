#include <bits/stdc++.h>

using namespace std;

int t, n, a[17][17], dp[17][1 << 17];

int solve(int i, int j) {
  if (i == n || j == (1 << (n + 1)) - 1) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int r = 0;
  for (int l = 0; l < n; l++) {
    if (!(j & (1 << l))) {
      r = max(r, a[i][l] + solve(i + 1, j | (1 << l)));
    }
  }
  return dp[i][j] = r;
}

int main() {
  scanf("%d", &t);
  for (int cn = 1; cn <= t; cn++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", cn, solve(0, 0));
  }
}
