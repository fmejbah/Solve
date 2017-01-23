/*
 * New.cpp
 *
 *  Created on: May 6, 2014
 *      Author: mejbah
 */




#include <iostream>
#include <cstdio>

using namespace std;

#define SIZE 3000

int factorial( int ary[], int n )
{
	int i, j, r, m;

	ary[0] = 1;
	j = 1;
	for( i = 1;  i < SIZE; ++i )
	{
		ary[i] = -1;
	}

	for( i = 1;  i <= n; ++i )
	{
		r = 0;
		for( j = 0;  ary[j] != -1; ++j)
		{
			m = ( ary[j] * i ) + r;
			ary[j] = m % 10;
			r = m / 10;
			if( ary[j+1] == -1 )
			{
				while( r > 0 )
				{
					ary[++j] = r % 10;
					r /= 10;
				}
			}
		}
	}
	return j;
}

int main()
{
	int n, i, ary[SIZE];

	while( scanf("%d", &n) == 1 )
	{
		cout << n << '!' << endl;

		i = factorial(ary, n);

		while(i--)
			cout << ary[i];
		cout << endl;
	}
	return 0;
}
