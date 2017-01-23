/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * UVA: 793 - Network Connections           #
 * Data Structures: Union Find/Disjoint Set #
 * Date: 06/10/15                           #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

int id[1000], sz[1000];

int root( int p )
{
    while( p != id[p] ) p = id[p];//, id[p]=id[id[p]];;          //For_Path_compression_id[i]=id[id[i]];
    return p;
}

bool connected( int p, int q )
{
    return root(p) == root(q);
}

void Union( int p, int q )
{
    int i = root(p);
    int j = root(q);
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
    int t, n, p, q, a, b;
    char c;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for( int i = 0; i <= n; i++ ) id[i] = i, sz[i] = 1;
        a = b = 0;
        getchar();
        while(1)
        {
            c = getchar();
            if( c == '\0' || c == '\n' || c == EOF) break;
            scanf("%d %d", &p, &q);
            if( c == 'c' ) Union(p,q);
            else root(p) == root(q) ? a++ : b++;
            c = getchar();
        }
        printf("%d,%d\n", a, b);
        if(t) puts("");
    }
    return 0;
}
