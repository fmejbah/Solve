#include <bits/stdc++.h>

int main()
{
    long long int n, f[55], i;

    f[0] = 0, f[1] = 1, f[2] = 2, f[3] = 3;
    for( i = 4; i <= 50; i++ )
        f[i] = f[i-1] + f[i-2];

    while( scanf("%lld", &n) == 1 )
    {
        if( n == 0 )
            return 0;
        printf("%lld\n", f[n]);
    }
}
