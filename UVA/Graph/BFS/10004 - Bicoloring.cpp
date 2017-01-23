/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 10004 - Bicoloring.cpp            #
 * Date: 04/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

#define M 201

vector<int> G[M];

bool BFS( int source, int n )
{
    int color[M];
    queue<int> Q;
    memset(color,-1,sizeof(color));
    color[source] = 1;
    /*
     * Use 0 and 1 for coloring. For source vertex use 1.
     * All vertex adjacent to source will be 1 - 0 = 1
     * And all vertex adjacent to vertex which is color by 0 is 1 - 0 = 1
     * If color is -1 note not visited yet.
     */
    Q.push(source);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for( int i = 0; i < G[u].size(); i++ )
        {
            int v = G[u][i];
            if( color[v] == -1 ) //Not visited yet
            {
                color[v] = 1 - color[u];
                /*
                 * If color[u] = 0 then color[v] = 1
                 * else if color[u] = 1 then color[v] = 0
                 */
                Q.push(v);
            }
            else if( color[v] == color[u] )
                return false;
                /*
                 * Both already colored
                 * If both coloring by same color return false
                 * Because u and v are adjacent
                 */
        }
    }
    return true;
}

int main()
{
    int n, l, u, v;

    while(1)
    {
        cin >> n;
        if(!n) return 0;
        cin >> l;
        while(l--)
        {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        BFS(0,n-1) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
        for( int i = 0; i < n; i++ )
            G[i].clear();
    }
    return 0;
}
