#include <bits/stdc++.h>

using namespace std;
typedef long long int i64;

i64 A[105][105];
i64 nCr( int n, int r )
{
    if( r == 1 ) return n;
    if( n == r ) return 1;
    if( A[n][r] != -1 ) return A[n][r];
    A[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
    return A[n][r];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out1.txt", "w", stdout);

    int n, r;
    for( int i = 0; i < 105; i++ )
        for( int j = 0; j < 105; j++ )
            A[i][j] = -1;
    while( scanf("%d%d", &n, &r) == 2 )
    {
        if( n == 0 && r == 0 )
            return 0;
        printf("%d things taken %d at a time is %lld exactly.\n", n, r, nCr(n,r));
    }
}
