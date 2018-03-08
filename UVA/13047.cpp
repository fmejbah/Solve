/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 13047
 * Date: 07 Nov 2016
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
  //freopen("13047.in", "r", stdin);
  //freopen("13047.out", "w", stdout);
  int T; cin >> T;
  for( int cn =  1; cn <= T; cn++ ) {
    string s; cin >> s;
    int ans = -1;
    for( int i = 0; i < s.length(); i++ ) {
      if( s[i] == '<' ) {
        ans = max(ans, 1);
        int x = 1;
        bool f = 0;
        for( int j = i+1; j < s.length(); j++ ) {
          if( j == i+1 && s[j] == '-' ) f = 1;
          if(f) {
            if( s[j] == '-' ) x++;
            else break;
          } else {
            if( s[j] == '=' ) x++;
            else break;
          }
        }
        ans = max(ans, x);
      }
    }
    for( int i = s.length() - 1; i >= 0; i-- ) {
      if( s[i] == '>' ) {
        ans = max(ans, 1);
        int x = 1;
        bool f = 0;
        for( int j = i-1; j >= 0; j-- ) {
          if( j == i-1 && s[j] == '-' ) f = 1;
          if(f) {
            if( s[j] == '-' ) x++;
            else break;
          } else {
            if( s[j] == '=' ) x++;
            else break;
          }
        }
        ans = max(ans, x);
      }
    }
    printf("Case %d: %d\n", cn, ans);
  }
}
