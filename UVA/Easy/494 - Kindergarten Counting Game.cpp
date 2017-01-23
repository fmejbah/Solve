/*
 * 494 - Kindergarten Counting Game.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: Biborno
 */




#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	int i, count;
	char s[10000];
	bool b;

	while(gets(s))
	{
		b = false;
		count = 0;
		for( i = 0; s[i] != '\0'; i++ )
		{
			if(!isalpha(s[i]) && b)
				b = false;
			if(isalpha(s[i]) && !b)
			{
				b = true;
				count++;
			}
		}
		if(count)
			cout << count << endl;
	}
	return 0;
}
