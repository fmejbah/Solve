/*########################################
 *                                       #
 * fb.com/mfmejbah                       #
 * fmejbah@gmail.com                     #
 * Light-OJ: 1009 - Back to Underworld   #
 * Graph: BFS Algorithm                  #
 * 16/5/15                               #
 *########################################
 */

#include <bits/stdc++.h>

using namespace std;

#define M 20005
#define INF 10000000
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)
#define loop0(i,n) for( int i = 0; i < n; i++ )
#define loop1(i,n) for( int i = 1; i <= n; i++ )
#define pb(x) push_back(x)
#define sz() size()

typedef vector<int> vi;

vi Graph[M];
set<int> s;

int bfs( int source )
{
    bool visited[M] = {0};
    int level[M], parents[M], ret1 = 0, ret2 = 1;
    queue<int> Q;

    Q.push(source);
    level[source] = 0;
    visited[source] = 1;
    s.erase(source);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for( int i = 0; i < Graph[u].size(); i++ )
        {
            int v = Graph[u][i];
            if(!visited[v])
            {
                level[v] = 1 - level[u];
                if(level[v]) ret1++;
                else ret2++;
                Q.push(v);
                visited[v] = 1;
                s.erase(v);
            }
        }
    }
    return max(ret1,ret2);
}

int main()
{
    int t, n, u, v;

    si(t);
    loop1(cn,t)
    {
        si(n);
        loop0(i,n)
        {
            si(u), si(v);
            Graph[u].pb(v);
            Graph[v].pb(u);
            s.insert(u);
            s.insert(v);
        }
        int a = bfs(u);
        while(!s.empty()) a += bfs(*s.begin());
        printf("Case %d: %d\n", cn, a);
        loop0(i,M) Graph[i].clear(), s.clear();
    }
}
