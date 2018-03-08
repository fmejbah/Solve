#include <bits/stdc++.h>

using namespace std;

int mod(int a, int b) {
  int ret = a % b;
  if (ret < 0) {
    ret += b;
  }
  return ret;
}

int extended_cuclid(int a, int b, int &x, int &y) {
  int xx = y = 0;
  int yy = x = 1;
  while (b) {
    int q = a / b;
    int t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}

int mod_inverse(int a, int m) {
  int x, y;
  int g = extended_cuclid(a, m, x, y);
  if (g > 1) {
    return -1;
  }
  return mod(x, m);
}

int main() {
  int T, n, p[13], r[13];
  long long int M, ans;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &n);
    M = 1;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", p + i, r + i);
      M *= p[i];
    }
    ans = 0;
    for (int i = 0; i < n; i++) {
      ans += ((M / p[i]) * mod_inverse((M / p[i]) % p[i], p[i]) * r[i]) % M;
    }
    printf("Case %d: %lld\n", cn, ans % M);
  }
}
