#include <bits/stdc++.h>

using namespace std;

int n;
int s[100];
bool taken[100] = {0};
vector <int> result;

void permutation(int i)
{
    if( result.size() == 6 )
    {
        for( int i = 0; i < 6; i++ )
        {
            printf("%d", result[i]);
            if(i != 5)
                printf(" ");
        }
        printf("\n");
        return;
    }
    for( ; i < n; i++ )
    {
        if( taken[i] == 0 )
        {
            taken[i] = 1;
            result.push_back(s[i]);
            permutation(i+1);
            taken[i] = 0;
            result.pop_back();
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    bool b = 0;
    while( scanf("%d", &n) == 1)
    {
        if(n == 0)
            return 0;
        if(b)
            printf("\n");
        for( int i = 0; i < n; i++ )
            scanf("%d", &s[i]);
        permutation(0);
        b = 1;
    }
}

