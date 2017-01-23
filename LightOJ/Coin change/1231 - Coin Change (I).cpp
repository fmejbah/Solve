/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * UVA: 1231 - Coin Change (I)              #
 * Dynamic Programming: Coin change         #
 * 8/7/15                                   #
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

int n, k, coins[51], number[51], store[51][21][1001];

int solve( int i, int taken_i, int amount )
{
    if( i >= n )
    {
        if( amount == k ) return 1;
        return 0;
    }
    if( amount == k ) return 1;
    if( store[i][taken_i][amount] != -1 ) return store[i][taken_i][amount];
    int ret1 = 0, ret2 = 0;
    if( taken_i < number[i] && amount + coins[i] <= k ) ret1 = solve(i, taken_i+1,amount+coins[i]);
    ret2 = solve(i+1,0, amount);
    return store[i][taken_i][amount] = (ret1 + ret2) % 100000007;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    si(t);
    loop1(cn,t)
    {
        si(n), si(k);
        loop0(i,n+1) loop0(j,21) loop0(l,k+1) store[i][j][l] = -1;
        //mem(store,-1);
        loop0(i,n) si(coins[i]);
        loop0(i,n) si(number[i]);
        printf("Case %d: %d\n", cn, solve(0,0,0));
    }
    return 0;
}
