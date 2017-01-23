/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 10260 - Soundex                   #
 * Date: 04/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char s[30];
    bool p1, p2, p3, p4, p5, p6;
    while( scanf("%s", s) == 1 )
    {
        p1 = p2 = p3 = p4 = p5 = p6 = true;
        for( int i = 0; s[i] != '\0'; i++ )
        {
            if( s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'H' || s[i] == 'W' || s[i] == 'Y' )
            {
                p1 = p2 = p3 = p4 = p5 = p6 = true;
            }
            else if( (s[i] == 'B' || s[i] == 'F' || s[i] == 'P' || s[i] == 'V') && p1 )
            {
                printf("1");
                p1 = p2 = p3 = p4 = p5 = p6 = true;
                p1 = false;
            }
            else if( (s[i] == 'C' || s[i] == 'G' || s[i] == 'J' || s[i] == 'K' || s[i] == 'Q' || s[i] == 'S' || s[i] == 'X' || s[i] == 'Z') && p2 )
            {
                printf("2");
                p1 = p2 = p3 = p4 = p5 = p6 = true;
                p2 = false;
            }
            else if( (s[i] == 'D' || s[i] == 'T') && p3 )
            {
                printf("3");
                p1 = p2 = p3 = p4 = p5 = p6 = true;
                p3 = false;
            }
            else if( s[i] == 'L' && p4 )
            {
                printf("4");
                p1 = p2 = p3 = p4 = p5 = p6 = true;
                p4 = false;
            }
            else if( (s[i] == 'M' || s[i] == 'N') && p5 )
            {
                printf("5");
                p1 = p2 = p3 = p4 = p5 = p6 = true;
                p5 = false;
            }
            else if( s[i] == 'R' && p6 )
            {
                printf("6");
                p1 = p2 = p3 = p4 = p5 = p6 = true;
                p6 = false;
            }
        }
        printf("\n");
    }
    return 0;
}
