/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 439 - Knight Moves                #
 * Date: 05/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

#define M 9
#define pii pair<int,int>

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
bool v[M][M];
int d[M][M];

void bfs( int sx, int sy )
{
    queue<pii> Q;
    memset(v,0,sizeof(v));
    Q.push(pii(sx,sy));
    d[sx][sy] = 0;
    v[sx][sy] = 1;
    while(!Q.empty())
    {
        pii s = Q.front();
        Q.pop();
        for( int i = 0; i < 8; i++ )
        {
            int tx = s.first + dx[i];
            int ty = s.second + dy[i];
            if( tx > 0 && tx < M && ty > 0 && ty < M && !v[tx][ty] )
            {
                d[tx][ty] = d[s.first][s.second] + 1;
                v[tx][ty] = 1;
                Q.push(pii(tx,ty));
            }
        }
    }
}
int main()
{
    char a[3], b[3];
    int w, x, y, z;
    while( scanf("%s %s", a, b) == 2 )
    {
        w = a[0] - 96;
        x = a[1] - '0';
        y = b[0] - 96;
        z = b[1] - '0';
        //cout << w << ' ' << x << ' ' << y << ' ' << z << endl;
        bfs(w,x);
        printf("To get from %s to %s takes %d knight moves.\n", a, b, d[y][z]);
    }
}
