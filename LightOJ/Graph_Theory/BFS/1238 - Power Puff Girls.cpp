/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * Light-OJ: 1238 - Power Puff Girls        #
 * Graph: 2D BFS Algorithm                  #
 * 18/5/15                                  #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

#define M 21
#define INF 10000000
#define si(x) scanf("%d", &x)
#define sc(x) scanf("%c", &x)
#define pi(x) printf("%d\n", x)
#define loop0(i,n) for( int i = 0; i < n; i++ )
#define loop1(i,n) for( int i = 1; i <= n; i++ )
#define pb(x) push_back(x)
#define sz() size()

typedef vector<int> vi;
typedef long long int lli;
typedef pair<int, int> pii;

//Direction array.
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int d[M][M], row, col;
bool v[M][M];
char Grid[M][M];

int BFS( pii s, pii h )
{
    queue<pii> Q;
    int sx = s.first, sy = s.second;
    for( int i = 0; i < M; i++ )
        for( int j = 0; j < M; j++ )
        {
            v[i][j] = 0;
            d[i][j] = 0;
        }
    Q.push(pii(sx,sy));
    v[sx][sy] = 1;
    while(!Q.empty())
    {
        pii s = Q.front();
        Q.pop();
        for( int i = 0; i < 4; i++ )
        {
            int tx = s.first + dx[i];
            int ty = s.second + dy[i];
            if( tx >= 0 && tx < row && ty >= 0 && ty < col && Grid[tx][ty] != '#' && Grid[tx][ty] != 'm' && !v[tx][ty] )
            {
                v[tx][ty] = 1;
                d[tx][ty] = d[s.first][s.second] + 1;
                Q.push(pii(tx,ty));
            }
        }
    }
    return d[h.first][h.second];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    pii a, b, c, h;

    si(t);
    loop1(cn,t)
    {
        si(row), si(col);
        loop0(i,row)
        {
            cin.ignore();
            loop0(j,col)
            {
                sc(Grid[i][j]);
                if( Grid[i][j] == 'a' )
                    a.first = i, a.second = j;
                else if( Grid[i][j] == 'b' )
                    b.first = i, b.second = j;
                else if( Grid[i][j] == 'c' )
                    c.first = i, c.second = j;
                else if( Grid[i][j] == 'h' )
                    h.first = i, h.second = j;
            }
        }
        printf("Case %d: %d\n", cn, max(BFS(a,h),max(BFS(b,h),BFS(c,h))));
    }
    return 0;
}
