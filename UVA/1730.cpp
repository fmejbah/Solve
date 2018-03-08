#include <bits/stdc++.h>

using namespace std;

#define M 20000000

long long int A[M+2];

void ff()
{
    for( int i = 2; i <= M; i++ )
        for( int j = i; j <= M; j += i )
            A[j] += i;

    for( int i = 2; i <= M; i++ )
        A[i] += A[i-1] + 1;
}

void f()
{
    for( int i = 2; i*i <= M; i++ )
        for( int j = i*i; j <= M; j += i )
            A[j] += i+(j/i <= i ? 0 : j/i);

    for( int i = 2; i <= M; i++ )
        A[i] += A[i-1] + i + 1;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    //clock_t s, e;
    //time(&s);
    f();
    int n;
    while( scanf("%d", &n) == 1 )
        if( n == 0 )
            return 0;
        else
            printf("%lld\n", A[n]);
    //time(&e);
    //double d = difftime(e, s);
    //cout << d << endl;
}
