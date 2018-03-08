#include <bits/stdc++.h>

using namespace std;

const int MAX = 112345;

int T, n, q, A[MAX], t, x, v;
long long int s;

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    printf("Case %d:\n", cn);
    scanf("%d%d", &n, &q);
    s = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", A + i);
      s += (n - 2 * i - 1) * 1LL * A[i];
    }
    while (q--) {
      scanf("%d", &t);
      if (t == 1) {
        printf("%lld\n", s);
      } else {
        scanf("%d%d", &x, &v);
        s -= (n - 2 * x - 1) * 1LL * A[x];
        A[x] = v;
        s += (n - 2 * x - 1) * 1LL * A[x];
      }
    }
  }
}
