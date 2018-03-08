#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  long long int x1, y1, x2, y2;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%lld%lld", &x1, &y1);
    scanf("%lld%lld", &x2, &y2);
    printf("Case %d: %lld\n", cn, __gcd(abs(x1 - x2), abs(y1 - y2)) + 1LL);
  }
}
