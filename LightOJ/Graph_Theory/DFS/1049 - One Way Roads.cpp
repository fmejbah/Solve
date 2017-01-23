/*###################################
 *                                  #
 * fb.com/mfmejbah                  #
 * fmejbah@gmail.com                #
 * Light-OJ: 1049 - One Way Roads   #
 * Graph                            #
 * 16/5/15                          #
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

vi v[101];
bool visited[101];
int ans, graph[101][101];

void call( int s )
{
    if(!visited[v[s][0]])
    {
        if( graph[s][v[s][0]] > 0 ) ans += graph[s][v[s][0]];
        visited[v[s][0]] = 1;
        call(v[s][0]);
    }
    else if(!visited[v[s][1]])
    {
        if( graph[s][v[s][1]] > 0 ) ans += graph[s][v[s][1]];
        visited[v[s][1]] = 1;
        call(v[s][1]);
    }
}

int main()
{
    int t, n, a, b, c, cost;

    si(t);
    loop1(cn,t)
    {
        si(n);
        cost = 0;
        loop0(i,n)
        {
            si(a), si(b), si(c);
            v[a].pb(b);
            v[b].pb(a);
            graph[a][b] = c;
            graph[b][a] = -c;
            cost += c;
        }
        memset(visited,0,sizeof(visited));
        ans = 0;
        visited[a] = 1;
        if( graph[v[a][1]][a] > 0 ) ans += graph[v[a][1]][a];
        call(a);
        printf("Case %d: %d\n", cn, min(ans,cost-ans));
        loop0(i,101) v[i].clear();
    }
}
