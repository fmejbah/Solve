/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * Timus: 1501. Sense of Beauty             #
 * Dynamic Programming: Print solution      #
 * 14/7/15                                  #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

#define M 2003
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
//#define first f
//#define second s

typedef vector<int> vi;
typedef long long int lli;
typedef pair<int, int> pii;

int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};

int store[1003][1003], direction[1003][1003], n;
char s1[1003], s2[1003];

bool solve( int i, int j, int z, int o )
{
    //if( i == n || j == n ) return 0;
    if( abs(z-o) > 1 ) return 0;
    if( store[i][j] != -1 ) return store[i][j];
    if( i == n && j == n ) return 1;

    bool ret1 = 0, ret2 = 0;
    if( z > o )
    {
        if( s1[i] == '1' ) ret1 = solve(i+1, j, z, o+1);
        if( s2[j] == '1' ) ret2 = solve(i, j+1, z, o+1);
    }
    else if( z < o )
    {
        if( s1[i] == '0' ) ret1 = solve(i+1, j, z+1, o);
        if( s2[j] == '0' ) ret2 = solve(i, j+1, z+1, o);
    }
    else
    {
        if( s1[i] == '1' ) ret1 = solve(i+1, j, z, o+1);
        else ret1 = solve(i+1, j, z+1, o);
        if( s2[j] == '1' ) ret2 = solve(i, j+1, z, o+1);
        else ret2 = solve(i, j+1, z+1, o);
    }
    if(ret1) direction[i][j] = 1;
    if(ret2) direction[i][j] = 2;
    return store[i][j] = ret1 || ret2;
}

void go( int i, int j )
{
    if( direction[i][j] == -1 ) return;
    if( direction[i][j] == 1 ) cout << 1, go(i+1,j);
    if( direction[i][j] == 2 ) cout << 2, go(i,j+1);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while( si(n) == 1 )
    {
        mem(store,-1);
        mem(direction,-1);
        scanf("%s%s", s1, s2);
        bool f1, f2;
        if( s1[0] == '0' ) f1 = solve(1,0,1,0);
        else f1 = solve(1,0,0,1);
        if( s2[0] == '0' ) f2 = solve(0,1,1,0);
        else f2 = solve(0,1,0,1);
        if(!f1&&!f2) puts("Impossible");
        else if(f1) cout << 1, go(1,0), puts("");
        else cout << 2, go(0,1), puts("");
    }
}
