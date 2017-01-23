#include <bits/stdc++.h>

using namespace std;

int A[205];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    for( int i = 0; i <= 200; i++ )
        A[i] = i*i*i;

    for( int a = 1; a <= 200; a++ )
    {
        for( int b = 2; b < a; b++ )
        {
            for( int c = b + 1; c < a; c++ )
            {
                if(A[b] + A[c] < A[a])
                    for( int d = c + 1; d < a; d++ )
                    {
                        if(A[b] + A[c] + A[d] > A[a])
                            break;
                        if(A[b] + A[c] + A[d] == A[a])
                        {
                            printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                            break;
                        }
                    }
            }
        }
    }
    return 0;
}
