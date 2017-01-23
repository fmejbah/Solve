/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * UVA: 1004 - Monkey Banana Problem        #
 * Dynamic Programming: Rock climbing       #
 * 8/7/15                             v     #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

#define M 1003
#define INF 10000000
#define mem(x,z) memset(x,z,sizeof(x))
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
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

int n, n2, grid[201][101], store[202][101];

int solve( int i, int j )
{
    //if( store[i][j] != -1 ) return store[i][j];
    if( i > 0 && i < n && j > 0 && j <= i )
        if( store[i][j] != -1 ) return store[i][j];
        else
            return store[i][j] = max(solve(i+1, j) + grid[i][j], solve(i+1, j+1) + grid[i][j]);
    else if( i >= n && i < n2 && j > 0 && j <= n2-i )
        if( store[i][j] != -1 ) return store[i][j];
        else
            return store[i][j] = max(solve(i+1, j) + grid[i][j], solve(i+1, j-1) + grid[i][j]);
    return 0;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    si(t);
    loop1(cn,t)
    {
        si(n);
        n2 = n << 1;
        //mem(store,-1);
        loop1(i,n) loop1(j,i) store[i][j] = -1;
        loopx(i,n+1,n2-1) loop1(j,n2-i) store[i][j] = -1;
        loop1(i,n) loop1(j,i) si(grid[i][j]);
        loopx(i,n+1,n2-1) loop1(j,n2-i) si(grid[i][j]);
        printf("Case %d: %d\n", cn, solve(1,1));
    }
    return 0;
}
