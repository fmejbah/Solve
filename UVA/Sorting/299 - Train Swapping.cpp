#include <iostream>
#include <cstdio>

using namespace std;

#define SWAP(a,b) do{		\
					a ^= b;	\
					b ^= a;	\
					a ^= b;	\
					}while(0);


int main()
{
    int t, l, a[55], s, i, j;

    cin >> t;

    while(t--)
    {
        cin >> l;
        s = 0;
        for( i = 0; i < l; i++ )
            cin >> a[i];

        for( i = 0; i < l; i++ )
            for( j = 0; j < l - i - 1; j++ )
                if( a[j] > a[j+1] )
                {
                    SWAP(a[j],a[j+1]);
                    s++;
                }
        printf("Optimal train swapping takes %d swaps.\n", s);
    }
    return 0;
}
