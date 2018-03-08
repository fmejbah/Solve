#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int t, n, m;

LL sum(int a, int b) {
  return b * (b + 1LL) / 2 - a * (a - 1LL) / 2;
}

LL csod(int n) {
  LL r = 0;
  for (m = 2; m * m <= n; m++);
  for (int i = 2; i * i <= n; i++) {
    r += i * (n / i - 1) + sum(m, n / i);
  }
  return r;
}

int main() {
  scanf("%d", &t);
  for (int cn = 1; cn <= t; cn++) {
    scanf("%d", &n);
    printf("Case %d: %lld\n", cn, csod(n));
  }
}
