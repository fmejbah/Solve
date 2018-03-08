#include <bits/stdc++.h>

using namespace std;

int t, n, m, a[101], c[101], A[100001];
bool possible[100001];

int main() {
  scanf("%d", &t);
  for (int cn = 1; cn <= t; cn++) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", c + i);
    }
    memset(possible, 0, sizeof possible);
    possible[0] = 1;
    for (int i = 0; i < n; i++) {
      memset(A, 0, sizeof A);
      for (int j = 0; j <= m; j++) {
        if (possible[j] && j + a[i] <= m && !possible[j + a[i]] && A[j] < c[i]) {
          possible[j + a[i]] = 1;
          A[j + a[i]] = A[j] + 1;
        }
      }
    }
    printf("Case %d: %d\n", cn, accumulate(possible + 1, possible + m + 1, 0));
  }
}
