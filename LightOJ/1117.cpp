#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

int main() {
  int T, n, m, a[16], ones, ans;
  ull b;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d", a + i);
    }
    ans = n;
    for (int i = 1; i < (1 << m); i++) {
      b = 0;
      ones = 0;
      for (int j = 0; (1 << j) <= i; j++) {
        if (i & (1 << j)) {
          if (b == 0) {
            b = a[j];
          } else {
            b = b * a[j] / __gcd(b, 1ull * a[j]);
          }
          ones++;
        }
        if (b > n) {
          break;
        }
      }
      if (b <= n) {
        if (ones&1) {
          ans -= n / b;
        } else {
          ans += n / b;
        }
      }
    }
    printf("Case %d: %d\n", cn, ans);
  }
}
