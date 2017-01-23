/*#######################################################
 *                                                      #
 * fb.com/mfmejbah                                      #
 * fmejbah@gmail.com                                    #
 * UVA: 10038 - Jolly Jumpers                           # 
 * Date: 29/10/15                                       #
 *#######################################################
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b, A[3003];
    while( scanf("%d", &n) == 1 )
    {
        scanf("%d", &a);
        for( int i = 0; i < n-1; i++ )
        {
            scanf("%d", &b);
            A[i] = abs(a-b);
            a = b;
        }
        sort(A,A+n-1);
        bool f = 1;
        for( int i = 0; i < n-1; i++ ) if( A[i] != i+1 ) f = 0;
        if(f) puts("Jolly");
        else puts("Not jolly");
    }
    return 0;
}
