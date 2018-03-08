#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define M 1000001
int marked[M/64+2];
#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x) marked[x/64] |= (1<<((x%64)/2))
void sieve( int n ) {
  for( int i = 3; i * i <= n; i += 2 )
    if(!on(i))
      for( int j = i * i; j <= n; j += i + i )
        mark(j);
}
bool isPrime( int n ) {
  return n > 1 && ( n == 2 || ((n&1) && !on(n)));
}


int main() {
  sieve(M);
  vector<int> primes;
  primes.push_back(2);
  for (int i = 3; i <= M; i += 2) {
    if (isPrime(i)) {
      primes.push_back(i);
    }
  }
  int T, d, a;
  LL n;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%lld", &n);
    d = 1;
    for (int i = 0; i < (int)primes.size() && primes[i] * 1LL * primes[i] <= n; i++) {
      a = 1;
      while (n % primes[i] == 0) {
        a++;
        n /= primes[i];
      }
      d *= a;
    }
    if (n > 1) {
      d <<= 1;
    }
    printf("Case %d: %d\n", cn, d - 1);
  }
}
