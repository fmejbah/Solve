#include <bits/stdc++.h>

using namespace std;

int T, n, d, a, x;

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &n, &d);
    a = 1;
    x = d;
    while (x % n != 0) {
      x = (10 * x + d) % n;
      a++;
    }
    printf("Case %d: %d\n", cn, a);
  }
}
