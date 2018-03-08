#include <bits/stdc++.h>

using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define xx first
#define yy second

typedef long long int LL;
typedef pair<int, LL> pill;

const int mod = 1e9 + 7;

vector<pill> primes;

int bigMod(int a, LL n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return a;
  }
  LL x = bigMod(a, n / 2);
  x = (x * x) % mod;
  if (n&1) {
    x *= a;
  }
  return x % mod;
}

int main() {
  int T, n, m, a;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &n, &m);
    primes.clear();
    for (int i = 2; i * 1LL * i <= n; i++) {
      if (n % i == 0) {
        a = 0;
        while (n % i == 0) {
          a++;
          n /= i;
        }
        primes.pb(mp(i, a * 1LL * m));
      }
    }
    if (n > 1) {
      primes.pb(mp(n, m));
    }
    a = 1;
    for (int i = 0; i < (int)primes.size(); i++) {
      primes[i].yy++;
      a = ((a * (bigMod(primes[i].xx, primes[i].yy) - 1LL + mod) % mod) % mod * bigMod(primes[i].xx - 1, mod - 2)) % mod;
    }
    printf("Case %d: %d\n", cn, a);
  }
}
