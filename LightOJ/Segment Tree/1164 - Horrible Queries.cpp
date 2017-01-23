/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * Light-OJ: 1080 - Binary Simulation       #
 * Graph: Segment Tree(lazy propagation)    #
 * 30/6/15                                  #
 *###########################################
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

#define M 100001

struct node
{
    i64 sum, prop;
}tree[3*M];

void update( int v, int tl, int tr, int l, int r, int x )
{
    if( r < l ) return;
    if( tl == l && tr == r )
    {
        tree[v].prop += x;
        tree[v].sum += (tr-tl+1)*x;
        return;
    }
    int tm = ( tl + tr ) >> 1;
    int left = v << 1;
    if( r <= tm ) update(left, tl, tm, l, r, x);
    else if( l > tm ) update(left+1, tm+1, tr, l, r, x);
    else
    {
        update(left, tl, tm, l, min(r,tm), x);
        update(left+1, tm+1, tr, max(l,tm+1), r, x);
    }
    tree[v].sum = tree[left].sum + tree[left+1].sum + (tr-tl+1)*tree[v].prop;
}

i64 query( int v, int tl, int tr, int l, int r, i64 carry = 0 )
{
    if( r < l ) return 0;
    if( tl == l && tr == r ) return tree[v].sum + carry*(tr-tl+1);

    int tm = ( tl + tr ) >> 1;
    int left = v << 1;

    if( r <= tm ) return query(left, tl, tm, l, r, carry+tree[v].prop);
    else if( l > tm ) return query(left+1, tm+1, tr, l, r, carry+tree[v].prop);
    else
    {
        i64 r1 = 0, r2 = 0;
        r1 = query(left, tl, tm, l, min(tm,r), carry+tree[v].prop);
        r2 = query(left+1, tm+1, tr, max(l,tm+1), r, carry+tree[v].prop);
        return r1+r2;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, n, q, x, y, v, type;

    scanf("%d", &t);
    for( int cn = 1; cn <= t; cn++ )
    {
        printf("Case %d:\n", cn);
        scanf("%d%d", &n, &q);
        memset(tree,0,sizeof(tree));
        while(q--)
        {
            scanf("%d%d%d", &type, &x, &y);
            if( type == 0 )
            {
                scanf("%d", &v);
                update(1,0,n-1,x,y,v);
            }
            else
            {
                printf("%lld\n" ,query(1,0,n-1,x,y));
            }
        }
    }
}
