/*
 * Learning.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: Biborno
 */



#include <iostream>

using namespace std;

typedef long long int lli;

lli mod( lli b, lli p, lli m )
{
	if( p == 0 )
		return 1;
	else if(!(p&1))
		return (((mod(b,p/2,m)%m)*(mod(b,p/2,m)%m))%m);
	else
		return (((b%m)*(mod(b,p-1,m)%m))%m);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	lli b, p, m;

	while( cin >> b >> p >> m )
	{
		cout << mod(b,p,m) << endl;
	}

	return 0;
}
