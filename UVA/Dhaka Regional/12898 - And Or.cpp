/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * uva: 1501. 12898 - And Or                #
 * 26/7/15                                  #
 *###########################################
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    long long int a, b;
    scanf("%d", &t);
    for( int i = 1; i <= t; i++ )
    {
        scanf("%lld%lld", &a, &b);
        long long int And = 0, Or = 0;
        for( int j = 0; j < 63; j++ )
        {
            if( a == b && (a&1) )
                And += (long long int)1<<j;
            if( a != b || (a&1) || (b&1) )
                Or += (long long int)1<<j;
            a >>= 1;
            b >>= 1;
            if( a == 0 && b == 0 ) break;
        }
        printf("Case %d: %lld %lld\n", i, Or, And);
    }
    return 0;
}
