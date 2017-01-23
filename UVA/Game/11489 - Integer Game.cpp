/*#######################################################
 *                                                      #
 * fb.com/mfmejbah                                      #
 * fmejbah@gmail.com                                    #
 * UVA: 11489 - Integer Game                            # 
 * Game Theory                                          #
 * Date: 26/10/15                                       #
 *#######################################################
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, n, t, a[10], x, cn = 0, m;
    string str;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        getline(cin, str);
        m = s = 0;
        for( int i = 0; i < 10; i++ ) a[i] = 0;
        for( int i = 0; i < str.size(); i++ )
        {
            x = str[i] - '0';
            a[x]++;
            s += x;
        }
        bool f = 0;
        if( str.size() == 1 ) f = 1;
        else if( str.size() == 2 ) f = 0;
        else
            while(1)
            {
                x = s % 3;
                if(x)
                {
                    if(a[x]) s -= x, a[x]--;
                    else if(a[x+3]) s -= x+3, a[x+3]--;
                    else if(a[x+6]) s -= x+6, a[x+6]--;
                    else { f = m&1; break; } 
                }
                else
                {
                    if(a[3]) s -= 3, a[3]--;
                    else if(a[6]) s -= 6, a[6]--;
                    else if(a[9]) s -= 9, a[9]--;
                    else { f = m&1; break; } 
                }
                m++;
            }
        if(f) printf("Case %d: S\n", ++cn);
        else printf("Case %d: T\n", ++cn);
    }
    return 0;
}
