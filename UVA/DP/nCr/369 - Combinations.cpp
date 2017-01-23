#include <iostream>

using namespace std;

long gcd(long a, long b)
{
    if ( a%b == 0 )
        return b;
    else
        return gcd(b,a%b);
}
void Divbygcd(long &a, long &b)
{
    long g = gcd(a,b);
    a /= g;
    b /= g;
}
long C(int n, int k)
{
    long numerator = 1, denominator = 1, toMul, toDiv, i;
    if(k > n/2)
        k = n - k; /* use smaller k */
    for ( i = k; i; i-- )
    {
        toMul = n - k + i;
        toDiv = i;
        Divbygcd(toMul,toDiv); /* always divide before multiply */
        Divbygcd(numerator,toDiv);
        Divbygcd(toMul,denominator);
        numerator *= toMul;
        denominator *= toDiv;
    }
    return numerator/denominator;
}

int main()
{
    int m, n;

    while(cin>>n>>m)
    {
        if( m == 0 && n == 0 )
            return 0;
        cout << n << " things taken " << m << " at a time is " << C(n,m) << " exactly." << endl;
    }
    return 0;
}
