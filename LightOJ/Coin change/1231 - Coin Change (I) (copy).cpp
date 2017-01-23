#include <bits/stdc++.h>

using namespace std;

int coin[51], c[51], make, n, store[51][1002];

int call( int i, int amount )
{
    if( i >= n )
        if( amount == make )
            return 1;
        else
            return 0;
    if( amount == make )
        return 1;
    if( amount > make )
        return 0;
    if( store[i][amount] != -1 )
        return store[i][amount];

    int ret = 0;

    for( int t = 1; t <= c[i]; t++ )
        if( amount + coin[i]*t <= make )
            ret += call(i+1,amount+coin[i]*t)%100000007;
        else
            break;

    ret += call(i+1,amount)%100000007;
    return store[i][amount] = ret%100000007;
}

int main()
{
    int t;

    scanf("%d", &t);
    for( int i = 1; i <= t; i++ )
    {

        memset(store,-1,sizeof(store));
        scanf("%d%d", &n, &make);

        for( int j = 0; j < n; j++ )
            scanf("%d", &coin[j]);
        for( int j = 0; j < n; j++ )
            scanf("%d", &c[j]);
        printf("Case %d: %d\n", i, call(0,0));
    }
    return 0;
}
