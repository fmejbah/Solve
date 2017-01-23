#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long int a, l, n, s, cn = 0;

    while( scanf("%lld %lld", &a, &l) == 2 )
    {
        if( a <= 0 && l <= 0 )
            return 0;

        n = a;
        s = 0;
        while( n <= l && n > 0)
        {
            if(n == 1)
            {
                s++;
                break;
            }
            if(n&1)
                n = 3*n + 1;
            else
                n /= 2;
            s++;
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", ++cn, a, l, s);
    }
    return 0;
}

