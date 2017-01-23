/*#########################################
 * fb.com/mfmejbah                        #
 * fmejbah@gmail.com                      #
 * UVA: 11777 - Automate the Grades       #
 * Date: 04/10/2015                       #
 *#######################################*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tc, cn = 0, t1, t2, f, a, ct[3], t;

    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d %d %d %d %d %d %d", &t1, &t2, &f, &a, &ct[0], &ct[1], &ct[2]);

        sort(ct,ct+3);

        t = t1 + t2 + f + a + (ct[1]+ct[2])/2.0;

        if( t >= 60 )
            if( t >= 70 )
                if( t >= 80 )
                    if( t >= 90 )
                        printf("Case %d: A\n", ++cn);
                    else
                        printf("Case %d: B\n", ++cn);
                else
                    printf("Case %d: C\n", ++cn);
            else
                printf("Case %d: D\n", ++cn);
        else
            printf("Case %d: F\n", ++cn);
    }
    return 0;
}
