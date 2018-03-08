/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 13081
 * Date: 10 Nov 2016
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
  //freopen("13081.in", "r", stdin);
  //freopen("13081.out", "w", stdout);
  int T; cin >> T;
  while(T--) {
    long long int l, r; cin >> l >> r;
    if( r - l + 1 > 3 ) cout << 0 << endl;
    else {
      long long int ans = -1;
      if( l == 0 ) ans = 1, l++;
      while( l <= r ) {
        int x = (l - 1) % 4;
        if( x == 0 ) ans = 0;
        else if( x == 1 )
          ans &= l;
        else if( x == 2 )
          ans &= l ^ (l - 1);
        else if( x == 3 )
          ans &= l ^ (l - 1) ^ (l - 2);
        l++;
      }
      cout << ans << endl;
    }
  }
}
