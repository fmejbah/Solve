/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 567 - Risk.cpp                    #
 * Date: 04/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

vector<int> G[21];

int bfs( int s, int d )
{
    int level[21] = {0};
    bool visited[21] = {0};
    //int p[21];
    queue<int> Q;
    level[s] = 0;
    visited[s] = 1;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for( int i = 0; i < G[u].size(); i++ )
        {
            int v = G[u][i];
            if(!visited[v])
            {
                level[v] = level[u] + 1;
                visited[v] = 1;
                //p[v] = u;
                Q.push(v);
            }
        }
    }
    return level[d];
}

int main()
{
    char s[100];
    int n, u, v, l = 1, cn = 0, x;
    while(gets(s))
    {
        if( l == 1 ) printf("Test Set #%d\n", ++cn);
        if( l < 20 )
        {
            istringstream num(s);
            bool f = 0;
            while(num >> x)
            {
                if( x > l && f )
                {
                    G[l].push_back(x);
                    G[x].push_back(l);
                }
                f = 1;
            }
            l++;
        }
        if( l == 20 )
        {
            cin >> n;
            while(n--)
            {
                cin >> u >> v;
                printf("%2d to %2d: %d\n", u, v, bfs(u,v));
            }
            l = 1;
            for( int i = 0; i < 21; i++ )
                G[i].clear();
            getchar();
            puts("");
        }
    }
}
