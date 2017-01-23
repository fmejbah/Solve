/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 11192 - Group Reverse             #
 * Date: 04/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

void GREV( int n, char *s )
{
	if( s[0] != '\0' )
	{
		int l = n;
		while(l--)
			printf("%c", s[l]);
		GREV(n,&s[n]);
	}
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	int n;
	char s[105];

	while( scanf("%d", &n) == 1 )
	{
		if(!n)
			return 0;
        scanf("%s", s);
		GREV(strlen(s)/n,s);
		printf("\n");
	}
	return 0;
}
