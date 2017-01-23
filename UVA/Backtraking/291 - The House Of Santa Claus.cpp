#include <bits/stdc++.h>

using namespace std;

bool p[6][6] = {
    {0,0,0,0,0,0},
    {0,0,1,1,0,1},
    {0,1,0,1,0,1},
    {0,1,1,0,1,1},
    {0,0,0,1,0,1},
    {0,1,2,3,4,0},
};
bool visited[6][6];
vector <int> result;

void call( int i )
{
    if( result.size() == 9 )
    {
        for( int i = 0; i < 9; i++ )
            cout << result[i];
        cout << endl;
        return;
    }
    for( int j = 1; j <= 5; j++ )
    {
        if(p[i][j] && visited[i][j] == 0 && visited[j][i] == 0 )
        {
            visited[j][i] = visited[i][j] = 1;
            result.push_back(j);
            call(j);
            result.pop_back();
            visited[j][i] = visited[i][j] = 0;
        }
    }
}
int main()
{
    //freopen("out.txt", "w", stdout);
    result.push_back(1);
    call(1);
}
