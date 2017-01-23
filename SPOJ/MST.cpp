/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Graph: Kruskal
 */
#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u, v;
    long long int weight;
    bool operator<( const edge& e ) const {
        return weight < e.weight;
    }
}E[100001];

int id[10001], sz[10001], n, e;

void MakeSet( int x )
{
    id[x] = x;
    sz[x] = 1;
}

int root( int x )
{
    while( x != id[x] ) x = id[x];	//For_Path_compression_id[i]=id[id[i]];
    return x;
}

void Union( int x, int y )
{
    int i = root(x);
    int j = root(y);
    if( i == j ) return;	//Important
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

long long int MST_KRUSKAL()
{
    long long int r = 0;
    for( int i = 1; i <= n; i++ )
        MakeSet(i);
    sort(E,E+e);
    for( int i = 0; i < e; i++ )
    {
        if( root(E[i].u) != root(E[i].v) )
        {
            r += E[i].weight;
            Union(E[i].u,E[i].v);
        }
    }
    return r;
}

int main()
{
    scanf("%d%d", &n, &e);
    for( int i = 0; i < e; i++ )
        scanf("%d%d%lld", &E[i].u, &E[i].v, &E[i].weight); 
    printf("%lld\n", MST_KRUSKAL());
    return 0;
}
