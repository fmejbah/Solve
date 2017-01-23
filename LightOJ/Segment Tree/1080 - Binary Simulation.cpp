/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * Light-OJ: 1080 - Binary Simulation       #
 * Graph: Segment Tree                      #
 * 29/6/15                                  #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

#define M 100001

bool tree[3*M];

void build( string s, int v, int tl, int tr )
{
	if( tl == tr )
		if( s[tl] == '0' ) tree[v] = 0;
		else tree[v] = 1;
	else
	{
		int tm = (tl + tr) >> 1;
		build (s, v<<1, tl, tm);
		build (s, (v<<1)+1, tm+1, tr);
	}
}

void update( int v, int tl, int tr, int l, int r )
{
    if(l > r) return;
    if( l == tl && tr == r )
    {
        tree[v] ^= 1;
        return;
    }
    int tm = ( tl + tr ) >> 1;
    int left = v << 1;
    if( r <= tm ) update(left, tl, tm, l, r);
    else if( l > tm ) update(left+1, tm+1, tr, l, r);
    else
    {
        update(left, tl, tm, l, min(r,tm));
        update(left+1, tm+1, tr, max(l,tm+1), r);
    }
}

bool get( int v, int tl, int tr, int pos )
{
    if( tl == pos && tr == pos ) return tree[v];
    int tm = ( tl + tr ) >> 1;
    if( pos <= tm )
        return tree[v] ^ get(v<<1, tl, tm, pos);
    else
        return tree[v] ^ get((v<<1)+1, tm+1, tr, pos);
}


int main()
{
    //freopen("in.txt", "r", stdin);
    int t, n, q, i, j;
    char type, s[M];

    scanf("%d", &t);
    for( int cn = 1; cn <= t; cn++ )
    {
        printf("Case %d:\n", cn);
        memset(tree,0,sizeof(tree));
        scanf("%s", s);
        n = strlen(s);
        //build(s,1,0,n-1);
        for( int i = 0; i < n; i++ )
            if( s[i] == '1' ) update(1,1,n,i+1,i+1);
        scanf("%d", &q);
        while(q--)
        {
            scanf(" %c ", &type);
            if( type == 'I' )
            {
                scanf("%d%d", &i, &j);
                update(1, 1, n, i, j);
            }
            else
            {
                scanf("%d", &i);
                printf("%d\n", get(1, 1, n, i));
            }
        }
    }
}
