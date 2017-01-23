#include <bits/stdc++.h>

using namespace std;

long GCD( long a, long b )
{
    if( b == 0 )
        return a;
    return GCD(b,a%b);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    long a, b;

    while( scanf("%ld%ld", &a, &b) == 2 )
    {
        if( GCD(a,b) == 1 )
            printf("%10ld%10ld    Good Choice\n\n", a, b);
        else
            printf("%10ld%10ld    Bad Choice\n\n", a, b);
    }
}
