/*##############################################
 *                                             #
 * fb.com/mfmejbah                             #
 * fmejbah@gmail.com                           #
 * Light-OJ: 1094 - Farthest Nodes in a Tree   #
 * Graph: DFS Algorithm                        #
 * 17/5/15                                     #
 *##############################################
 */

#include <bits/stdc++.h>

using namespace std;

#define M 30001
#define INF 10000000
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)
#define loop0(i,n) for( int i = 0; i < n; i++ )
#define loop1(i,n) for( int i = 1; i <= n; i++ )
#define pb(x) push_back(x)
#define sz() size()

typedef vector<int> vi;
typedef long long int lli;

const int infinity = 1000000000;

vector<int> edge[M], cost[M];

bool visited[M] = {0};
int value[M];
vi val;

void DFS( int s, int u, int x )
{
    loop0(i,edge[s].sz())
    {
        if(!visited[edge[s][i]])
        {
            visited[edge[s][i]] = 1;
            DFS(edge[s][i], s, i);
        }
    }
    if( s != 0 )
    {
        val.pb(value[u]+value[s]+cost[u][x]);
        value[u] = max(value[u],value[s]+cost[u][x]);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, u, v, w, r;

    si(t);
    loop1(cn,t)
    {
        si(n);
        loop0(i,n-1)
        {
            si(u), si(v), si(w);
            edge[u].pb(v), edge[v].pb(u);
            cost[u].pb(w), cost[v].pb(w);
        }
        loop0(i,n)
        {
            visited[i] = 0;
            value[i] = 0;
        }
        visited[0] = 1;
        DFS(0,0,0);
        sort(val.begin(),val.end());
        int ans = val[val.sz()-1];
        printf("Case %d: %d\n", cn, ans);
        loop0(i,n) edge[i].clear(), cost[i].clear(), val.clear();
    }
    return 0;
}
