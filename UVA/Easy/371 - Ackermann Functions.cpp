#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long int l, h, n, s, m, v, a;

    while(1)
    {
        scanf("%lld %lld", &l, &h);
        if( !h && !l )
            return 0;

        if(l>h)
        {
            l ^= h;
            h ^= l;
            l ^= h;
        }
        m = 0;
        a = h;
        while(a>=l)
        {
            n = a;
            s = 0;
            if(a == 1)
                s = 3;
            while(n>1)
            {
                if(n&1)
                    n = 3*n + 1;
                else
                    n /= 2;
                s++;
            }
            if(s >= m)
            {
                m = s;
                v = a;
            }
            a--;
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", l, h, v, m);
    }
    return 0;
}

