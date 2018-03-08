#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int main() {
  int T, n, pre, m;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &n);
    LL ans = n;
    pre = n;
    m = 1;
    for (int i = 2; i * 1LL * i <= n; i++) {
      m = n / i;
      ans += (pre - m) * (i - 1LL) + m;
      pre = m;
      m = i;
    }
    ans += (pre - m) * 1LL * m;
    printf("Case %d: %lld\n", cn, ans);
  }
}
