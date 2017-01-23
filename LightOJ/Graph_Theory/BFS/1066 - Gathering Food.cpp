/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * Light-OJ: 1066 - Gathering Food          #
 * Graph: BFS Algorithm                     #
 * 8/6/15                                   #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

#define M 5007
#define INF 10000000
#define si(x) scanf("%d", &x)
#define sc(x) scanf("%c", &x)
#define pi(x) printf("%d\n", x)
#define loop0(i,n) for( int i = 0; i < n; i++ )
#define loop1(i,n) for( int i = 1; i <= n; i++ )
#define loopx(i,x,n) for( int i = x; i <= n; i++ )
#define pb(x) push_back(x)
#define sz() size()

typedef vector<int> vi;
typedef long long int lli;
typedef pair<int, int> pii;

//Direction array.
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

char grid[11][11], mx;
int n;
pii a;

int BFS( char d )
{
    queue<pii> Q;
    int dis[12][12] = {0};
    bool visited[12][12] = {0};
    Q.push(a);
    visited[a.first][a.second] = 1;

    while(!Q.empty())
    {
        pii u = Q.front();
        Q.pop();
        loop0(i,4)
        {
            int tx = u.first + dx[i];
            int ty = u.second + dy[i];
            if( !visited[tx][ty] && tx >= 0 && tx < n && ty >= 0 && ty < n && (grid[tx][ty] == '.' || grid[tx][ty] == d) )
            {
                visited[tx][ty] = 1;
                dis[tx][ty] = dis[u.first][u.second] + 1;
                Q.push(pii(tx,ty));
                if( grid[tx][ty] == d )
                {
                    grid[tx][ty] = '.';
                    a.first = tx;
                    a.second = ty;
                    return dis[tx][ty];
                }
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    set<char> s;
    si(t);
    loop1(cn,t)
    {
        si(n);
        mx = 'A';
        loop0(i,n)
        {
            loop0(j,n)
            {
                cin >> grid[i][j];
                if( grid[i][j] == 'A' ) a.first = i, a.second = j;
                if( grid[i][j] >= 'A' && grid[i][j] <= 'Z' ) s.insert(grid[i][j]);
            }
        }
        int ans = 0;
        s.erase('A');
        grid[a.first][a.second] = '.';
        for( set<char>::iterator it = s.begin(); it != s.end(); it++ )
        {
            int r = BFS(*it);
            if( r != -1 ) ans += r;
            else
            {
                ans = -1;
                break;
            }
        }
        printf("Case %d: ", cn);
        if( ans != -1 ) pi(ans);
        else puts("Impossible");
        s.clear();
    }
}











