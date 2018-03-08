/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 13032
 * Date: 10 Nov 2016
 */

#include <bits/stdc++.h>

using namespace std;

const int mod =  1000000007;

int main()
{
  //freopen("13032.in", "r", stdin);
  //freopen("13032.out", "w", stdout);
  int T; cin >> T;
  for( int cn = 1; cn <= T; cn++ ) {
    int n; cin >> n;
    long long int A[n];
    for( int i = 0; i < n; i++ )
      cin >> A[i];
    sort(A, A+n);
    long long int ans = 1;
    for( int i = 0; i < n; i++ )
      ans = (ans * (A[i]-i)) % mod;
    printf("Case %d: %d\n", cn, ans);
  }
}
