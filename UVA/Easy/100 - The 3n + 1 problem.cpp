#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int i, j, n, max, len;

    while(scanf("%d %d", &i, &j) == 2)
    {
        printf("%d %d ", i, j);
        if(i>j)
        {
            i ^= j;
            j ^= i;
            i ^= j;
        }
        max = 0;
        while(i<=j)
        {
            n = i;
            len = 1;
            while(n!=1)
            {
                len++;
                if(n&1)
                    n = 3*n + 1;
                else
                    n /= 2;
            }
            if(len>max)
                max = len;
            i++;
        }
        printf("%d\n", max);
    }
    return 0;
}
