#include <bits/stdc++.h>

using namespace std;
typedef long long int i64;

i64 nCr( i64 n, i64 r )
{
    if( n == r )
        return 1;
    if( r == 1 )
        return n;
    i64 ans = 1;
    r = min(r,n-r);
    for( i64 i = 1; i <= r; i++, n-- )
    {
        ans *= n;
        ans /= i;
    }
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out1.txt", "w", stdout);

    i64 n, r;
    while( scanf("%lld%lld", &n, &r) == 2 )
    {
        if( n == 0 && r == 0 )
            return 0;
        printf("%lld\n", nCr(n,r));
    }
}
