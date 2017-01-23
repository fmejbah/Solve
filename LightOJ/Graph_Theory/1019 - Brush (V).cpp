/*##############################################
 *                                             #
 * fb.com/mfmejbah                             #
 * fmejbah@gmail.com                           #
 *                                             #
 * LightOJ: 1019 - Brush (V)                   #
 *##############################################
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define M 100
#define pb(x) push_back(x)
#define si(x) scanf("%d", &x)
#define pi(x) printf("%d\n", x)
#define loop0(i,n) for( int i = 0; i < n; i++ )
#define loop1(i,n) for( int i = 1; i <= n; i++ )
int INF = 1<<28;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, m, u, v, w, G[101][101];

    si(t);
    loop1(cn,t)
    {
        si(n), si(m);
        loop1(i,n) loop1(j,n) G[i][j] = i == j ? 0 : INF;

        while(m--)
        {
            si(u), si(v), si(w);
            G[u][v] = G[v][u] = min(w,G[u][v]);
        }
        loop1(k,n) loop1(i,n) loop1(j,n) G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
        if(G[1][n] == INF ) printf("Case %d: Impossible\n", cn);
        else printf("Case %d: %d\n", cn, G[1][n]);
    }
    return 0;
}
