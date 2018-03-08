#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int MOD = 1000003;
const int MAX = 1123456;

int T, n, k, fact[MAX], inv_k, inv_n_k;

int mod (LL a, int b) {
  int ret = a % b;
  if (ret < 0) {
    ret += b;
  }
  return ret;
}

int extended_euclid (int a, int b, int &x, int &y){
  int xx = y = 0;
  int yy = x = 1;
  while (b) {
    int q = a/b;
    int t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

int mod_inverse (int a, int n){
  int x, y;
  int d = extended_euclid (a, n, x, y);
  if (d > 1) {
    return -1;
  }
  return mod(x,n);
}

int main () {
  fact[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fact[i] = mod(fact[i - 1] * 1LL * i, MOD);
  }
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &n, &k);
    inv_k = mod_inverse(fact[k], MOD);
    inv_n_k = mod_inverse(fact[n-k], MOD);
    printf("Case %d: %d\n", cn, mod(fact[n] * 1LL * inv_k * inv_n_k, MOD));
  }
}
