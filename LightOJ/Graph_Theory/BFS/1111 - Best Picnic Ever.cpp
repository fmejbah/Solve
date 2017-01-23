/*####################################
 *                                   #
 * fb.com/mfmejbah                   #
 * fmejbah@gmail.com                 #
 * Light-OJ: 1111 - Best Picnic Ever #
 * Graph: BFS Algorithm              #
 * 17/5/15                           #
 *####################################
 */

#include <bits/stdc++.h>

using namespace std;

#define M 1002
#define INF 10000000
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)
#define loop0(i,n) for( int i = 0; i < n; i++ )
#define loop1(i,n) for( int i = 1; i <= n; i++ )
#define pb(x) push_back(x)
#define sz() size()

typedef vector<int> vi;
typedef long long int lli;

vi Graph[M];

set<int> BFS( int s )
{
    bool visited[M] = {0};
    queue<int> Q;
    set<int> ret;
    Q.push(s);
    visited[s] = 1;
    ret.insert(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        loop0(i,Graph[u].sz())
        {
            int v = Graph[u][i];
            if(!visited[v])
            {
                visited[v] = 1;
                ret.insert(v);
                Q.push(v);
            }
        }
    }
    return ret;
}

int main()
{
    int t, k, n, m, u, v;
    vi km;

    si(t);
    loop1(cn,t)
    {
        si(k), si(n), si(m);
        loop0(i,k) si(u), km.pb(u);
        loop0(i,m)
        {
            si(u), si(v);
            Graph[u].pb(v);
        }
        set<int> ret = BFS(km[0]);
        vi s(ret.begin(),ret.end());
        loop1(i,k-1)
        {
            set<int> s1 = BFS(km[i]);
            vi ans(M);
            vi::iterator it = set_intersection(s.begin(),s.end(),s1.begin(),s1.end(),ans.begin());
            ans.resize(it-ans.begin());
            s = ans;
        }
        printf("Case %d: %d\n", cn, s.sz());
        loop1(i,n) Graph[i].clear(), km.clear();
    }
    return 0;
}
