/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 10653 - Bombs! NO they are Mines!!#
 * Date: 05/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define M 1005

//Direction array.
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int d[M][M], row, col;
bool cell[M][M], v[M][M];

void BFS( int sx, int sy )
{
    queue<pii> Q;
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
            if( tx >= 0 && tx <= row && ty >= 0 && ty <= col && cell[tx][ty] && !v[tx][ty] )
            {
                v[tx][ty] = 1;
                d[tx][ty] = d[s.first][s.second] + 1;
                Q.push(pii(tx,ty));
            }
        }
    }
}

int main()
{
    int n, r, c, a, b, y, z, boom;
    while( scanf("%d%d", &row, &col) == 2 )
    {
        if( row == 0 && col == 0 ) return 0;
        memset(cell,1,sizeof(cell));
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d%d", &r, &boom);
            while(boom--)
            {
                scanf("%d", &c);
                cell[r][c] = 0;
            }
        }
        scanf("%d%d%d%d", &a, &b, &y, &z);
        BFS(a,b);
        printf("%d\n", d[y][z]);
    }
}
