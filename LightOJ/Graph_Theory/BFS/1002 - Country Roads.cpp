/*###################################
 *                                  #
 * fb.com/mfmejbah                  #
 * fmejbah@gmail.com                #
 * Light-OJ: 1002 - Country Roads   #
 * Graph: Dijkstra Algorithm        #
 * 27/5/15                          #
 *###################################
 */

#include <bits/stdc++.h>

using namespace std;

#define M 5007
#define INF 10000000
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)
#define loop0(i,n) for( int i = 0; i < n; i++ )
#define loop1(i,n) for( int i = 1; i <= n; i++ )
#define pb(x) push_back(x)
#define sz() size()

typedef vector<int> vi;
typedef long long int lli;

vector<int> edge[502];
int node[502], graph[502][502];

//edge[i][j] = jth node connected with i

void BFS( int source )
{
    queue<int> Q;
    Q.push(source);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < edge[u].size(); i++)
        {
            int v = edge[u][i];
            if( v != source )
            {
                if( node[v] == -1 )
                {
                    node[v] = max(node[u],graph[u][v]);
                    Q.push(v);
                }
                else if( node[v] > max(node[u],graph[u][v]) )
                {
                    node[v] = max(node[u],graph[u][v]);
                    Q.push(v);

                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t, m, u, v, w, s, n;

    si(t);
    loop1(cn,t)
    {
        si(n), si(m);
        loop0(i,n)
            loop0(j,n)
                graph[i][j] = (i==j) ? 0 : INF;
        while(m--)
        {
            si(u), si(v), si(w);
            if( w < graph[u][v] ) graph[u][v] = graph[v][u] = w;
            edge[u].pb(v);
            edge[v].pb(u);
        }
        si(s);
        loop0(i,n)
        {
            node[i] = -1;
        }
        node[s] = 0;
        BFS(s);
        printf("Case %d:\n", cn);
        loop0(i,n)
        {
            if( node[i] != -1 ) pi(node[i]);
            else puts("Impossible");
        }
        loop0(i,n) edge[i].clear();
    }
    return 0;
}

