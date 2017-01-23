/*
 * Working.cpp
 *
 *  Created on: Jun 18, 2014
 *      Author: Biborno
 */




#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

char convertNumber[100] = {'\0'};

void srev( char *s )
{
	int len, k, l;
	char c;
	len = strlen(s);

	for( k = 0, l = len - 1; k < len/2; k++, l-- )
	{
		c = s[k];
		s[k] = s[l];
		s[l] = c;
	}
}

int decimal( char *number, int base )
{
	int decimal = 0, i, r, a;

	for( i = strlen(number) - 1, r = 0; i >= 0; i-- , r++ )
	{
		if(isdigit(number[i]))				/* if( number[i] > 47 && number[i] < 58 ) */
			a = number[i] - '0';
		else
			a = number[i] - 55;
		decimal += a * pow(base,r);
	}
	return decimal;
}

void baseConvert( int number, int base )
{
	int i, r;

	if(!number)
	{
		convertNumber[0] = '0';
		convertNumber[1] = '\0';
		return;
	}
	for( i = 0; number > 0; i++ )
	{
		r = number % base;
		number /= base;
		if( r < 10 )
			convertNumber[i] = r + '0';
		else
			convertNumber[i] = r + 55;
	}
	convertNumber[i] = '\0';

	srev(convertNumber);
}

int main()
{
	int base, convertBase, decimalNumber = 0, length;
	char number[100] = {'\0'};

	while( cin >> number >> base >> convertBase )
	{
		decimalNumber = decimal(number,base);

		baseConvert(decimalNumber, convertBase);
		length = strlen(convertNumber);

		if(length>7)
			printf("%7s\n", "ERROR");
		else
				printf("%7s\n", convertNumber);
	}
	return 0;
}