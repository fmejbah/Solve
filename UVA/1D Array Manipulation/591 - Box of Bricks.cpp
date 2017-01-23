/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 591 - Box of Bricks               #
 * Date: 04/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, cn = 0, A[55], avg, ans;

    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            return 0;
        avg = 0;
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &A[i]);
            avg += A[i];
        }
        avg /= n;
        ans = 0;
        for( int i = 0; i < n; i++ )
            if( A[i] > avg )
                ans += A[i] - avg;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++cn, ans);
    }
	return 0;
}
