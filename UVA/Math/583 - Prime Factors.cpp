#include <iostream>
#include <cstdio>
#include <cmath>


using namespace std;

int main()
{
    int n, sq;
    bool b = false;

    while(1)
    {
        b = false;
        scanf("%d", &n);
        if(!n) return 0;

        printf("%d = ", n);
        if( n < 0 )
        {
            printf("-1");
            n = -n;
            b = true;
        }
        if(b)
            printf(" x ");
        while(n%2==0)
        {
            printf("2");
            n /= 2;
            if(n>1)
                printf(" x ");
        }
        sq = sqrt(n);
        for( int i = 3; i <= sq; i += 2 )
        {
            while(n%i==0)
            {
                printf("%d", i);
                n /= i;
                if(n>1)
                    printf(" x ");
            }
        }
        if(n>1)
            printf("%d", n);
        printf("\n");
    }
}


/*

vector<int> vi;
int A[3125001] = {0};
int N = 10000;

inline int set1( int N, int pos )
{
    return ( N | (1<<pos) );
}

inline bool check( int N, int pos )
{
    return (bool) ( N & (1<<pos) );
}

void sieve()
{
    for( int i = 0; i < 3125001; i++ )
        A[i] = 0;
    int sq = sqrt(N);
    A[0] = set1(A[0],0);
    //A[0] = set1(A[0],1);

    for( int i = 4; i < N; i += 2 )
        A[i/32] = set1(A[i/32],i%32);

    for( int i = 3; i <= sq; i += 2 )
        if(!check(A[i/32],i%32))
            for( int j = i*i; j < N; j += i )
                A[j/32] = set1(A[j/32],j%32);
}

void primeFactor(int n)
{
    if(!check(A[n>>5],n&31))
    {
        vi.push_back(n);
        return;
    }
    else if(!(n&1))
    {
        vi.push_back(2);
        n /= 2;
        primeFactor(n);
    }
    else
    {
        for( int i = 3; i <= n ; i++ )
        {
            if( !check(A[i>>5],i&31) && (n%i) == 0 )
            {
                vi.push_back(i);
                n /= i;
                break;
            }
        }
        primeFactor(n);
    }
}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    sieve();
    int n;
    while(1)
    {
        scanf("%d", &n);

        if(n == 0) break;

        printf("%d = ", n);

        if(n<0)
        {
            vi.push_back(-1);
            n *= -1;
        }
        primeFactor(n);
        sort(vi.begin(),vi.end());
        for( int i = 0; i < vi.size(); i++ )
        {
            printf("%d", vi[i]);
            if( i < (vi.size() - 1) )
                printf(" x ");
        }
        NL;
        vi.clear();
    }
    return 0;
}
*/
