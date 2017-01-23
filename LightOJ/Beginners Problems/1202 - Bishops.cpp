/*##################################################
 * Biborno                                         #
 * fb.com/mfmejbah                                 #
 * fmejbah@gmail.com                               #
 *                                                 #
 * LightOJ: 1202 - Bishops.cpp                     #
 *##################################################
 */
 #include  <bits/stdc++.h>

using namespace std;

int main()
{
    long long int t, r1, c1, r2, c2;

    cin >> t;
    for( int cn = 1; cn <= t; cn++ )
    {
        cin >> r1 >> c1 >> r2 >> c2;
        if( abs(r1-r2) == abs(c1-c2) || (r1+c1 == r2+c2) ) printf("Case %d: 1\n", cn);
        else if( ((r1+c1)&1) != ((r2+c2)&1) ) printf("Case %d: impossible\n", cn);
        else printf("Case %d: 2\n", cn);
    }
}
