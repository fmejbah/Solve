/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * SPOJ: UPDATEIT - Update the array !      #
 * Tree: BIT                                #
 * 4/7/15                                   #
 *###########################################
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

i64 tree[10001], n;

void update( int idx, int val )
{
    while( idx <= n )
    {
        tree[idx] += val;
        idx += idx & (-idx);
    }
}

i64 query( int idx )
{
    i64 sum = 0;
    while( idx > 0 )
    {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, u, l, r, v, q;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &u);
        for( int i = 0; i <= n; i++ ) tree[i] = 0;
        while(u--)
        {
            scanf("%d%d%d", &l, &r, &v);
            update(l+1,v);
            update(r+2,-v);
        }
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d", &u);
            printf("%lld\n",  query(u+1));
        }
    }
}

