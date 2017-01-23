#include <cstdio>

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int m, n, sum;
    double d;
    char s[25] = {'\0'};

    while( gets(s) )
    {
        m = n = 0;
        //First
        for( int i = 0; s[i] != '\0'; i++ )
            if( s[i] >= 65 && s[i] <= 90 )
                m += (s[i] - 'A') + 1;
            else if( s[i] >= 97 && s[i] <= 122 )
                m += (s[i] - 'a') + 1;

        if( m % 9 != 0 )
            m = m % 9;
        else
            m = 9;
        //Second
        gets(s);
        for( int i = 0; s[i] != '\0'; i++ )
            if( s[i] >= 65 && s[i] <= 90 )
                n += (s[i] - 'A') + 1;
            else if( s[i] >= 97 && s[i] <= 122 )
                n += (s[i] - 'a') + 1;

        if( n % 9 != 0 )
            n = n % 9;
        else
            n = 9;

        if( m < n )
            d = ((double)m/(double)n) * 100.0;
        else
            d = ((double)n/(double)m) * 100.0;

        printf("%.2f %%\n", d);
    }
    return 0;
}
