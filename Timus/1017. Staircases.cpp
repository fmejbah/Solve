/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * Timus: 1017. Staircases                  #
 * Dynamic Programming: like Coin change    #
 * 11/7/15                                  #
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

long long dp[501][501];
int n;
long long calc(int i,int m)
{
    if(m==0) return 1;
    if(dp[i][m]!=-1) return dp[i][m];

    long long sum=0;
    for(int j=i+1;j<=m;j++)
        sum=sum+calc(j,m-j);
    return dp[i][m]=sum;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n)==1)
    {
        //memset(dp,-1,sizeof(dp));
        printf("%lld\n",calc(0,n)-1);

    }
    return 0;
}
