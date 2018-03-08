#include <bits/stdc++.h>

using namespace std;

#define M 10000001
#define sqrtM 3162
#define on(x) (marked[x>>6] & (1<<((x&63)>>1)))
#define mark(x) marked[x>>6] |= (1<<((x&63)>>1))

int marked[M/64+2];

void sieve() {
  for (int i = 3; i <= sqrtM; i += 2) {
    if(!on(i)) {
      for (int j = i * i; j <= M; j += i + i) {
        mark(j);
      }
    }
  }
}

bool isPrime( int n ) {
  return n > 1 && ( n == 2 || ((n&1) && !on(n)));
}


int main() {
  int T, n, ans, m = 0;
  sieve();
  int primes[664580];
  primes[0] = 2;
  for (int i = 3; i < M; i += 2) {
    if (isPrime(i)) {
      primes[++m] = i;
    }
  }
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &n);
    ans = 0;
    for (int i = 0, j = m; i <= j; ) {
      while (i <= j && primes[i] + primes[j] > n) {
        j--;
      }
      while (i <= j && primes[i] + primes[j] < n) {
        i++;
      }
      if (primes[i] + primes[j] == n) {
        ans++;
        i++;
        j--;
      }
    }
    printf("Case %d: %d\n", cn, ans);
  }
}
