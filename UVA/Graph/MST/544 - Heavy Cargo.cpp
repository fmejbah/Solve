/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * UVA: 544 - Heavy Cargo                   #
 * Algorithm: MST Prim                      # 
 * Date: 28/10/15                           #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
vector<int> edge[202], cost[202];
int d[202], n;
pair<int, int> parent[202];
//edge[i][j] = jth node connected with i
//cost[i][j] = cost of that edge

void prim( int source )
{
    for( int i = 0; i <= n; i++ ) d[i] = 0;
    d[source] = 1000000;
    set< pair<int, int> > s;
    for( int i = 1; i <= n; i++ ) s.insert(make_pair(d[i], i));
    int u, v, w;
    while(!s.empty())
    {
        u = s.rbegin()->second;
        w = s.rbegin()->first;
        s.erase(make_pair(w,u));
        for( int i = 0; i < edge[u].size(); i++  )
        {
            v = edge[u][i];
            w = cost[u][i];
            if( s.find(make_pair(d[v], v)) != s.end() && d[v] < w )
            {
                parent[v] = make_pair(u, w);
                s.erase(make_pair(d[v], v));
                d[v] = w;
                s.insert(make_pair(d[v], v));
            }
        }
    }
}

void print()
{
    cout << "Edge - > cose\n";
    for( int i = 1; i <= n; i++ ) cout << i <<  " - " << parent[i].first << " - > " << parent[i].second << endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int e, w, cn = 0;
    string u, v;

    while(cin >> n >> e)
    {
        if( !n && !e ) return 0;
    for( int i = 0, j = 0; i < e; i++ )
    {
        cin >> u >> v >> w;
        if(!m[u]) m[u] = ++j;
        if(!m[v]) m[v] = ++j;
        edge[m[u]].push_back(m[v]);
        edge[m[v]].push_back(m[u]);
        cost[m[u]].push_back(w);
        cost[m[v]].push_back(w);
    }
    cin >> u >> v;
    prim(m[u]);
    int a = m[u], b = m[v], ans = parent[m[v]].second;
    while( a != parent[b].first )
    {
        b = parent[b].first;
        ans = min(ans, parent[b].second);
    }
    cout << "Scenario #" << ++cn << '\n' << ans << " tons\n" << endl;
        m.clear();
        for( int i = 0; i <=n; i++ )
            edge[i].clear(), cost[i].clear();
    }
    return 0;
}
