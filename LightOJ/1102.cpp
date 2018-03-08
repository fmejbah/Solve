#include <bits/stdc++.h>

using namespace std;

#define MAX 2123456

typedef long long int LL;

const int MOD = 1e9 + 7;

int fact[MAX];

int mod(LL a) {
  a %= MOD;
  if (a < 0) {
    a += MOD;
  }
  return a;
}

int bigMod(int a, int n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return a;
  }
  LL x = bigMod(a, n / 2);
  x = mod(x * x);
  if (n&1) {
    x = mod(x * a);
  }
  return x;
}

int nCr(int n, int r) {
  int d = mod(fact[r] * 1LL * fact[n - r]);
  return mod(fact[n] * 1LL * bigMod(d, MOD - 2));
}

int main() {
  int T, n, k, ans;
  fact[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fact[i] = mod(i * 1LL * fact[i - 1]);
  }
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &n, &k);
    ans = nCr(n + k - 1, n);
    printf("Case %d: %d\n", cn, ans);
  }
}
