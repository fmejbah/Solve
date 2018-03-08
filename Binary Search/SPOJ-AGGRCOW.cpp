/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 * Binary Search
 * SPOJ-AGGRCOW.cpp
 * Date: 28 Aug 2016
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t, n, c, A[100000], l, h;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &c);
    for( int i = 0; i < n; i++ )
      scanf("%d", A+i);
    sort(A, A+n);
    l = 0, h = A[n-1];
    while( l < h ) {
      int m = l + (h - l) / 2, cn = 1;
      for( int i = 1, j = 0; i < n; i++ )
        if( A[i] - A[j] > m ) {
          cn++;
          j = i;
        }
      if( cn < c ) h = m;
      else l = m + 1;
    }
    printf("%d\n", l);
  }
}
