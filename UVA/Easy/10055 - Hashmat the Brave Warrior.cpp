/*
 * New.cpp
 *
 *  Created on: May 31, 2014
 *      Author: Biborno
 */


#include <iostream>


using namespace std;

#define ABS(x)   ( (x) > 0 ? (x) : (-(x)) )

int main()
{
    long long int a, b;
    while(cin>>a>>b)
    	cout << ABS(a-b) << endl;
	return 0;
}
