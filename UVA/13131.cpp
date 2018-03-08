/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 13131
 * Date: 10 Nov 2016
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
  //freopen("13131.in", "r", stdin);
  //freopen("13131.out", "w", stdout);
  int T; cin >> T;
  while(T--) {
    int n, k; cin >> n >> k;
    long long int s = 0;
    for( int i = 1; i * i <= n; i++ ) {
      if( n % i == 0 ) {
      s += i % k ? i : 0;
      if( i * i != n ) {
        s += (n/i) % k ? (n/i) : 0;
      }
      }
    }
    cout << s << endl;
  }
}
