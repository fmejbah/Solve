/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * p10651
 * Date: 04 Nov 2016
 * Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int dp[1 << 12 + 2];

inline bool check( int n, int p ) {
  return n & (1 << p);
}

int numberOfOnes( int n ) {
  int r = 0;
  while(n) {
    r += n&1;
    n >>= 1;
  }
  return r;
}

int solve( int mask ) {
  if(!mask) return 0;
  if(!((mask - 1) & mask)) return 1;
  int& ret = dp[mask];
  if( ret != -1 ) return ret;
  ret = numberOfOnes(mask);
  for( int i = 0; i < 10; i++ ) {
    if( check(mask, i) && check(mask, i+1) && !check(mask, i+2) ) {
      int m = mask;
      m |= 1 << (i + 2);
      m &= ~(1 << i);
      ret = min(ret, solve(m & ~(1 << (i+1))));
    }
    if( !check(mask, i) && check(mask, i+1) && check(mask, i+2) ) {
      int m = mask;
      m |= 1 << i;
      m &= ~(1 << (i + 2));
      ret = min(ret, solve(m & ~(1 << (i+1))));
    }
  }
  return ret;
}

int main()
{
  //freopen("p10651.in", "r", stdin);
  //freopen("p10651.out", "w", stdout);
  int n; scanf("%d", &n);
  while(n--) {
    int mask = 0;
    for( int i = 0; i < 12; i++ ) {
      char c; cin >> c;
      if( c == 'o' ) mask |= 1 << i;
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(mask));
  }
}
