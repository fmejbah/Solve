/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 13050
 * Date: 07 Nov 2016
 */

#include <bits/stdc++.h>

using namespace std;

const int mod = 912;
int A[1001][1001];

int main()
{
  //freopen("13050.in", "r", stdin);
  //freopen("13050.out", "w", stdout);
  for( int i = 1; i < 1001; i++ )
    A[0][i] = A[i][0] = 1;
  for( int i = 1; i <= 1000; i++ )
    for( int j = 1; j <=  1000; j++ )
      A[i][j] = (A[i-1][j] + A[i][j-1]) % mod;
  /*
  for( int i = 0; i < 8; i++ ) {
    for( int j = 0; j < 8; j++ )
      printf("%5d ", A[i][j]);
    puts("");
  }
  */
  int T; cin >> T;
  for( int cn = 1; cn <= T; cn++ ) {
    int r, c, q; cin >> r >> c >> q;
    printf("Case %d\n", cn);
    for( int qn = 1; qn <= q; qn++ ) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      if( x1 + y1 == 0 || (x2 == r-1 && y2 == c-1) ) {
        printf("   Query %d: %d\n", qn, 0);
        continue;
      }
      int ans = A[r-1][c-1], a = 0, b = 0;
      //cout << "ans: " << ans << endl;
      while( x1 <= x2 ) {
        //cout << "(x1, y2): " << x1 << ' ' << y2 << ", A[x1][y2]: " << A[x1][y2] << endl;
        //cout << "b: " << b << endl;
        //cout << "r-x1, c-y2: " << r-x1 << ' ' << c-y2 << ", A[][]: " << A[r-x1][c-y2] << endl;
        if( x1 == x2 && y1 < y2 ) b += A[x1][y2-1];
        a = (a + (((((A[x1][y2] - b) % mod) + mod) % mod)  * A[r-x1-1][c-y2-1]) % mod) % mod;
        //cout << "a: " << a << endl;
        b = A[x1][y2];
        x1++;
      }
      b = 0;
      while( y1 < y2 ) {
        a = (a + ((((A[x2][y1] - b) % mod + mod) % mod) * A[r-x2-1][c-y1-1]) % mod) % mod;
        //cout << "a: " << a << endl;
        b = A[x2][y1];
        y1++;
      }
      printf("   Query %d: %d\n", qn, (((ans - a) % mod) + mod) % mod);
    }
  }
}
