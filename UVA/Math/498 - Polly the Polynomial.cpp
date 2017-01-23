/*#######################################################
 *                                                      #
 * fb.com/mfmejbah                                      #
 * fmejbah@gmail.com                                    #
 * UVA: 498 - Polly the Polynomial                      #
 * Math
 * Date: 13/10/15                                       #
 *#######################################################
 */

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int x, sum;
    char s[10000];
    vector<int> c;
    istringstream iss;
    while(gets(s) != NULL)
    {
        iss.str(s);
        while(iss >> x) c.push_back(x);
        iss.clear();
        gets(s);
        iss.str(s);
        bool f = 1;
        while(iss >> x)
        {
            sum = c[0];
            for( int i = 1; i < c.size(); i++ )
                sum *= x, sum += c[i];
            if(f) f = 0, cout << sum;
            else cout << " " << sum;
        }
        puts("");
        iss.clear();
        c.clear();
    }
    return 0;
}