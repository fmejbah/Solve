/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * Light-OJ: 1263 - Equalizing Money        #
 * Graph: BFS Algorithm                     #
 * 18/5/15                                  #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

#define M 1002
#define INF 10000000
#define si(x) scanf("%d", &x)
#define sc(x) scanf("%c", &x)
#define pi(x) printf("%d\n", x)
#define loop0(i,n) for( int i = 0; i < n; i++ )
#define loop1(i,n) for( int i = 1; i <= n; i++ )
#define loopx(i,x,n) for( int i = x; i <= n; i++ )
#define pb(x) push_back(x)
#define sz() size()
#define first f
#define second s

typedef vector<int> vi;
typedef long long int lli;
typedef pair<int, int> pii;

int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};

vi Graph[M];
int money[M];
set<int> s;

bool BFS( int source, int avg )
{
    bool visited[M] = {0};
    queue<int> Q;
    int m = money[source]-avg;
    visited[source] = 1;
    Q.push(source);
    s.erase(source);
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
                m += money[v]-avg;
                Q.push(v);
                s.erase(v);
            }
        }
    }
    return m==0;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, n, m, u, v, sum, avg;

    si(t);
    loop1(cn,t)
    {
        sum = 0;
        si(n), si(m);
        loop1(i,n) si(money[i]), sum += money[i], s.insert(i);
        loop0(i,m)
        {
            si(u), si(v);
            Graph[u].pb(v);
            Graph[v].pb(u);
        }
        avg = sum/n;
        if( sum % n != 0 ) printf("Case %d: No\n", cn);
        else
        {
            while( s.sz() != 0 )
            {
                if(!BFS(*s.begin(),avg))
                {
                    printf("Case %d: No\n", cn);
                    break;
                }
            }
            if( s.sz() == 0 ) printf("Case %d: Yes\n", cn);
        }
        s.clear();
        loop1(i,n) Graph[i].clear();
    }
    return 0;
}
