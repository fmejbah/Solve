/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * LightOJ: 1012 - Guilty Prince.cpp
 */
#include <bits/stdc++.h>

using namespace std;

#define M 21

typedef pair<int, int> pii;

char cell[M][M];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int row, col;

int bfs( int sx, int sy )
{
    int ret = 1;
    bool visited[M][M] = {0};
    visited[sx][sy] = 1;
    queue<pii> Q;
    Q.push(pii(sx,sy));
    while(!Q.empty())
    {
        pii u = Q.front();
        Q.pop();
        for( int i = 0; i < 4; i++ )
        {
            int vx = u.first + dx[i];
            int vy = u.second + dy[i];
            if( vx >= 0 && vx < row && vy >= 0 && vy < col && !visited[vx][vy] && cell[vx][vy] != '#' )
            {
                visited[vx][vy] = 1;
                Q.push(pii(vx,vy));
                ret++;
            }
        }
    }
    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, x, y;

    scanf("%d", &t);
    for( int cn = 1; cn <= t; cn++ )
    {
        scanf("%d%d", &col, &row);

        for( int i = 0; i < row; i++ )
        {
            for( int j = 0; j < col; j++ )
            {
                scanf(" %c", &cell[i][j]);
                if( cell[i][j] == '@' )
                {
                    x = i, y = j;
                }
            }
        }
        printf("Case %d: %d\n", cn, bfs(x,y));
    }
    return 0;
}
