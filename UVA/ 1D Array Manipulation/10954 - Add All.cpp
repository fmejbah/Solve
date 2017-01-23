/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 10954 - Add All                   #
 * Date: 04/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A[5005], i, j, n, key, sum;

    while(1)
    {
        scanf("%d", &n);
        if(!n)
            return 0;
        for( i = 0; i < n; i++ )
            scanf("%d", &A[i]);

        sort(A,A+n);

        sum = 0;
        for( i = 1; i < n; i++ )
        {
            A[i] += A[i-1];
            sum += A[i];

            //Sorted
            key = A[i];
            j = i + 1;
            while( j < n && A[j] < key )
            {
                A[j-1] = A[j];
                j++;
            }
            A[j-1] = key;
        }
        printf("%d\n", sum);
    }
    return 0;
}
