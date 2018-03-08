/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 13028
 * Date: 10 Nov 2016
 */

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int bigMod( int n ) {
  if(!n) return 1;
  long long int x = bigMod(n/2);
  x = (x * x) % mod;
  if(n&1) x = (3 * x) % mod;
  return x;
}

int main()
{
  //freopen("13028.in", "r", stdin);
  //freopen("13028.out", "w", stdout);
  int T; cin >> T;
  for( int cn = 1; cn <= T; cn++ ) {
    string s; cin >> s;
    long long int n = 0;
    for( int i = 0; i < s.length(); i++ )
      n = (10 * n + (s[i]-'0')) % (mod-1);
    n = bigMod(n) + 1;
    n = (n * 500000004) % mod;
    printf("Case %d: %d\n", cn, n);
  }
}
