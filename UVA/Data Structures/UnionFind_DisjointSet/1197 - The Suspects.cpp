/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * UVA: 1197 - The Suspects                 #
 * Data Structures: Union Find/Disjoint Set #
 * Date: 06/10/15                           #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

int id[30003], sz[30003];

int root( int p )
{
    while( p != id[p] ) p = id[p];
    return p;
}

void Union( int p, int q )
{
    int i = root(p);
    int j = root(q);
    if( i == j ) return;
    if( sz[i] < sz[j] )
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n, m, k, x, y;
    while( scanf("%d%d", &n, &m) == 2 && ( n || m ) )
    {
        for( int i = 0; i < n; i++ ) id[i] = i, sz[i] = 1;
        while(m--)
        {
            scanf("%d%d", &k, &x);
            while(--k)
            {
                scanf("%d", &y);
                Union(x,y);
            }
        }
        printf("%d\n", sz[root(0)]);
    }
    return 0;
}
