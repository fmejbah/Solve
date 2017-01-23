#include <bits/stdc++.h>

#define PI acos(-1)
#define S(a) scanf("%d", &a)
#define S1(a,b) scanf("%d%d", &a, &b)
#define S2(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define SLL(a) scanf("%lld", &a)
#define SLL2(a,b) scanf("%lld%lld", &a, &b)
#define SLL3(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)
#define SS(a) scanf("%s", a)
#define SC(a) scanf("%c", &a)
#define SD(a) scanf("%lf", &a)
#define P(a) printf("%d", a)
#define PLL(a) printf("%lld", a)
#define PD(a) printf("%lf", a)
#define PC(a) printf("%c", a)
#define PS(a) printf("%s", a)
#define NL printf("\n")

#define FOR(i,a,b) for( i = a; i <= b; i++ )
#define FOR2(i,a,b) for( i = a; i <= b; i += 2 )
#define RFOR(i,a,b) for( i = a; i >= b; i-- )
#define For(i,a) for( i = 0; i < a; i++ )

#define max3(a,b,c) max(a,max(b,c)
#define min3(a,b,c) min(a,min(b,c)

#define PB push_back


using namespace std;

typedef long long int lli;
typedef vector<int> vi;

int N = 1000000, A[1000000/32+2] = {0};
#define set(N,pos) ( N | (1<<pos))
#define check(N,pos) ( N & (1<<pos) )

void sieve()
{
    //for( int i = 0; i < 3125001; i++ )
        //A[i] = 0;
    int sq = sqrt(N);
    A[0] = set(A[0],0);
    A[0] = set(A[0],1);

    for( int i = 4; i < N; i += 2 )
        A[i>>5] = set(A[i>>5],(i&31));

    for( int i = 3; i <= sq; i += 2 )
        if(!check(A[i>>5],(i&31)))
            for( int j = i*i; j < N; j += (i<<1) )
                A[j>>5] = set(A[j>>5],(j&31));
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    sieve();
    int n, i, b;
    bool flag = true;

    while(1)
    {
        S(n);
        if(!n)
            return 0;

        FOR2(i,3,n/2)
        {
            b = n - i;
            if(!check(A[i>>5],(i&31)) && !check(A[b>>5],(b&31)))
            {
                printf("%d = %d + %d\n", n, i, b);
                flag = false;
                break;
            }
        }
        if(flag)
            printf("Goldbach's conjecture is wrong.\n");
        flag = true;
    }
    return 0;
}
