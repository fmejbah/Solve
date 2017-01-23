/*#######################################################
 *                                                      #
 * fb.com/mfmejbah                                      #
 * fmejbah@gmail.com                                    #
 * UVA: 847 - A Multiplication Game                     # 
 * Game Theory                                          #
 * Date: 24/10/15                                       #
 *#######################################################
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n, p, m;
    while(cin >> n)
    {
        p = 1;
        bool f = 0;
        while( p < n )
        {
            p *= 9;
            if( p >= n ) f = 1;
            p *= 2;
        }
        if(f) cout << "Stan wins.\n";
        else cout << "Ollie wins.\n";
    }
    return 0;
}
