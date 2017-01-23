/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * UVA: 599 - The Forrest for the Trees     #
 * Data Structures: Graph/Number of trees   #
 * Date: 10/10/15                           #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

int id[27], sz[27];

void makeSet( int x )
{
    id[x] = x;
    sz[x] = 1;
}

int root( int x )
{
    while( x != id[x] )
        x = id[x];
    return x;
}

void Union( int x, int y )
{
    int i = root(x);
    int j = root(y);
    if( i == j ) return;
    if( sz[i] < sz[j] )
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    char s[53];

    scanf("%d", &t);
    while(t--)
    {
        for( int i = 0; i < 27; i++ ) makeSet(i);
        while( scanf("%s", s) == 1 )
        {
            if( s[0] == '*' ) break;
            Union(s[1]-'A',s[3]-'A');
        }
        scanf("%s", s);
        int a = 0;
        set<int> b;
        for( int i = 0; s[i] != '\0'; i++ )
            if( s[i] >= 'A' && s[i] <= 'Z' )
            {
                if( sz[root(s[i]-'A')] == 1 ) a++;
                b.insert(root(s[i]-'A'));
            }
        printf("There are %d tree(s) and %d acorn(s).\n", (int)b.size()-a, a);
    }
    return 0;
}
