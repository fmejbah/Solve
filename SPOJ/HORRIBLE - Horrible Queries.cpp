/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * SPOJ: HORRIBLE - Horrible Queries        #
 * Segment Tree: lazy propagation           #
 * 30/6/15                                  #
 *###########################################
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

#define M 262145

struct node
{
    i64 sum, prop;
}tree[M];

void update( i64 v, i64 tl, i64 tr, i64 l, i64 r, i64 x )
{
    if( r < l ) return;
    if( tl == l && tr == r )
    {
        tree[v].prop += x;
        tree[v].sum += (tr-tl+1)*x;
        return;
    }
    i64 tm = ( tl + tr ) >> 1;
    i64 left = v << 1;
    if( r <= tm ) update(left, tl, tm, l, r, x);
    else if( l > tm ) update(left+1, tm+1, tr, l, r, x);
    else
    {
        update(left, tl, tm, l, min(r,tm), x);
        update(left+1, tm+1, tr, max(l,tm+1), r, x);
    }
    tree[v].sum = tree[left].sum + tree[left+1].sum + (tr-tl+1)*tree[v].prop;
}

i64 query( i64 v, i64 tl, i64 tr, i64 l, i64 r, i64 carry = 0 )
{
    if( r < l ) return 0;
    if( tl == l && tr == r ) return tree[v].sum + carry*(tr-tl+1);

    i64 tm = ( tl + tr ) >> 1;
    i64 left = v << 1;

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

    i64 t, n, q, x, y, v, type;

    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for( i64 i = 0; i <= M; i++ )
            tree[i].prop = tree[i].sum = 0;
        while(q--)
        {
            cin >> type >> x >> y;
            if( type == 0 )
            {
                cin >> v;
                update(1,1,n,x,y,v);
            }
            else
                cout << query(1,1,n,x,y) << endl;
        }
    }
}
