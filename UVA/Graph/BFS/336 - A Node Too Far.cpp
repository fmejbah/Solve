/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 336 - A Node Too Far.cpp          #
 * Date: 04/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

vector<int> G[31];
int m[100000];      //Use for mapping.

int BFS( int s, int t, int node )
{
    int level[31] = {0};
    bool visited[31] = {0};
    queue<int> Q;
    level[m[s]] = 0;
    visited[m[s]] = 1;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for( int i = 0; i < G[m[u]].size(); i++ )
        {
            int v = G[m[u]][i];
            if(!visited[m[v]])
            {
                level[m[v]] = level[m[u]] + 1;
                visited[m[v]] = 1;
                Q.push(v);
            }

        }
    }
    int ans = 0;
    //Calculate how many node not
    for( int i = 0; i < node; i++ )
        if( level[i] == 0 && m[s] != i && m[s] != -1 ) ans++;
        // If level = 0 and it's not source then its not reachable from source
        else if( level[i] > t ) ans++;      // Here t is TTL level. If TTL level is > t then it's not reachable
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, a, b, node, cn = 0, x, y;

    while( scanf("%d", &n) == 1 )
    {
        if( n == 0 ) return 0;
        memset(m,-1,sizeof(m));
        node = 0;
        for( int i = 0; i < n; i++ )
        {
            scanf("%d%d", &a, &b);
            if( m[a] == -1 ) m[a] = node++;
            if( m[b] == -1 ) m[b] = node++;
            G[m[a]].push_back(b);
            G[m[b]].push_back(a);
        }
        while( scanf("%d%d", &x, &y) == 2 )
        {
            if( x == 0 && y == 0 ) break;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++cn, BFS(x,y,node), x, y);
        }
        for( int i = 0; i <= 31; i++ )
            G[i].clear();
    }
}


/*
input_iterator_tag
1
1 1
25 0
1 0
1 1
0 0
5
1 2 2 3 3 4 4 5 6 7
1 0
1 1
1 2
1 3
1 4
1 5
1 6
1 7
0 0
0

*/

/*
output

Case 1: 0 nodes not reachable from node 25 with TTL = 0.
Case 2: 0 nodes not reachable from node 1 with TTL = 0.
Case 3: 0 nodes not reachable from node 1 with TTL = 1.
Case 4: 6 nodes not reachable from node 1 with TTL = 0.
Case 5: 5 nodes not reachable from node 1 with TTL = 1.
Case 6: 4 nodes not reachable from node 1 with TTL = 2.
Case 7: 3 nodes not reachable from node 1 with TTL = 3.
Case 8: 2 nodes not reachable from node 1 with TTL = 4.
Case 9: 2 nodes not reachable from node 1 with TTL = 5.
Case 10: 2 nodes not reachable from node 1 with TTL = 6.
Case 11: 2 nodes not reachable from node 1 with TTL = 7.

*/
