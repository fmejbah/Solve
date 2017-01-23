/*#######################################################
 *                                                      #
 * fb.com/mfmejbah                                      #
 * fmejbah@gmail.com                                    #
 * UVA: 10341 - Solve It                                #  
 * Bisection Method                                     #  
 * Date: 29/10/15                                       #
 *#######################################################
 */

#include <bits/stdc++.h>

using namespace std;

double p, q, r, s, t, u, x1, x2, f1, f2, x, e = .00000005;

double f( double x )
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while( scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) == 6 )
    {
        x1 = 0.0, x2 = 1.0;
        f1 = f(x1);
        f2 = f(x2);
        if( f1*f2 == 0 ) printf("%.4f\n", f1 == 0 ? x1 : x2 );
        else if( f1*f2 > 0 ) puts("No solution");
        else
        {
            while(1)
            {
                x = (x1 + x2)/2.0;
                f2 = f(x);
                if( f1*f2 < 0 )
                    x2 = x;
                else
                {
                    x1 = x;
                    f1 = f2;
                }
                if( fabs(x1-x2) < e )
                {
                    printf("%.4f\n", (x1+x2)/2.0);
                    break;
                }
            }
        }
    }
    return 0;
}
