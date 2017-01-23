#include <stdio.h>
#define SWAP(a,b) do{		\
					a ^= b;	\
					b ^= a;	\
					a ^= b;	\
					}while(0);
					
int main(void) {
	int a[52], i, j, k, n, l;

    scanf("%d", &l);

    while(l--)
    {
        scanf("%d", &n);

        for( i = 1; i <= n; i++ )
        	scanf("%d", &a[i]);
        	
        k = 0;
        for( i = 1; i < n; i++ )
        	for( j = 1; j <= n - i; j++ )
        		if( a[j] > a[j+1])
        		{
        			SWAP(a[j],a[j+1]);
        			k++;
        		}
        
        printf("Optimal train swapping takes %d swaps.\n", k);
    }
	return 0;
}
