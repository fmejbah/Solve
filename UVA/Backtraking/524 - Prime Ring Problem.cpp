#include <bits/stdc++.h>

using namespace std;

int A[20], n;
bool t[20] = {0}, isPrime[100];
vector <int> r;

void prime()
{
    isPrime[2] = 1;
    for( int i = 3; i < 100; i += 2 )
        isPrime[i] = 1;

    for( int i = 3; i < 10; i+= 2 )
        if(isPrime[i])
            for( int j = 3*i; j < 100; j += 2*i )
            isPrime[j] = 0;
}

void permutation()
{
    if( r.size() == n )
    {
        if( !isPrime[ r[0] + r[n-1] ] )
            return;
        //for( int i = 0; i < n - 1; i++ )
            //if( !isPrime[ r[i] + r[i+1] ] )
               //return;
        printf("1");
        for( int i = 1; i < n; i++)
            printf(" %d", r[i]);
        printf("\n");
        return;
    }
    for( int i = 1; i < n; i++ )
    {
        if( t[i] == 0 && isPrime[i+1+r[r.size()-1]] )
        {
            t[i] = 1;
            r.push_back(i+1);
            permutation();
            t[i] = 0;
            r.pop_back();
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out3.txt", "w", stdout);
    //prime();
    //for( int i = 0; i <= 50; i++ )
        //if( isPrime[i] )
            //printf("isPrime[%d] = true;\n", i);
    //for( int i = 0; i < 20; i++ )
        //A[i] = i + 1;
    isPrime[2] = true;
    isPrime[3] = true;
    isPrime[5] = true;
    isPrime[7] = true;
    isPrime[11] = true;
    isPrime[13] = true;
    isPrime[17] = true;
    isPrime[19] = true;
    isPrime[23] = true;
    isPrime[29] = true;
    isPrime[31] = true;
    isPrime[37] = true;
    isPrime[41] = true;
    isPrime[43] = true;
    isPrime[47] = true;
    r.push_back(1);
    int cn = 0;
    while( scanf("%d", &n) == 1 )
    {
        if(cn)
            printf("\n");
        printf("Case %d:\n", ++cn);
        permutation();
    }
}
