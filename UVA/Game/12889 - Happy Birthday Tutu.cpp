/*#######################################################
 *                                                      #
 * fb.com/mfmejbah                                      #
 * fmejbah@gmail.com                                    #
 * UVA: 12889 - Happy Birthday Tutu                     #
 * Game Theory                                          #
 * Date: 24/10/15                                       #
 *#######################################################
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, a, m;
    bool f;
    scanf("%d", &t);
    while(t--)
    {
        f = 1;
        scanf("%d%d", &n, &m);
        for( int i = 1; i < n; i++ )
        {
            scanf("%d", &a);
            if( m != a ) f = 0;
        }
        if( f || n < 2 ) cout << "Better luck next time!\n";
        else cout << "Happy Birthday Tutu!\n";
    }
    return 0;
}
