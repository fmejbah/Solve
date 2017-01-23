/*######################################
 * fb.com/mfmejbah                     #
 * fmejbah@gmail.com                   #
 * UVA: 383 - Shipping Routes          #
 * Date: 04/10/2015                    #
 *####################################*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, m, x, n, p, G[31][31], cn = 0;
    string s1, s2;
    map<string, int> mp;
    scanf("%d", &t);
    puts("SHIPPING ROUTES OUTPUT");
    while(t--)
    {
        scanf("%d%d%d", &m, &n, &p);
        for( int i = 0; i < m; i++ )
        {
            cin >> s1;
            mp[s1] = i;
        }
        for( int i = 0; i < m; i++ )
            for( int j = 0; j < m; j++ )
                if( i == j ) G[i][i] = 0;
                else G[i][j] = 10000000;
        for( int i = 0; i < n; i++ )
        {
            cin >> s1 >>  s2;
            G[mp[s1]][mp[s2]] = G[mp[s2]][mp[s1]] = 1;
        }
        for( int k = 0; k < m; k++ )
            for( int i = 0; i < m; i++ )
                for( int j = 0; j < m; j++ )
                    if( G[i][k] + G[k][j] < G[i][j] )
                        G[i][j] = G[i][k] + G[k][j];
        printf("\nDATA SET  %d\n\n", ++cn);
        for( int i = 0; i < p; i++ )
        {
            cin >> x >> s1 >> s2;
            if( G[mp[s1]][mp[s2]] == 10000000 ) puts("NO SHIPMENT POSSIBLE");
            else cout << '$' <<100*x*G[mp[s1]][mp[s2]] << endl;
        }
    }
    puts("\nEND OF OUTPUT");
    return 0;
}
