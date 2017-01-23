/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * SPOJ: HORRIBLE - Horrible Queries        #
 * Tree: BIT                                #
 * 4/7/15                                   #
 *###########################################
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define M 100003

lli bit1[M], bit2[M], n;

void update( lli bit[], int idx, lli val )
{
    while( idx <= n )
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

lli query( lli bit[], int idx )
{
    lli sum = 0;
    while( idx > 0 )
    {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    lli t, q, l, r, v, type;

    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
        while(q--)
        {
            cin >> type >> l >> r;
            if( type == 0 )
            {
                cin >> v;
                update(bit1,l,v); update(bit1,r + 1,-v);
                update(bit2,l,-v*(l - 1)); update(bit2,r + 1,v * r);
            }
            else
                printf("%lld\n",query(bit1,r) * r + query(bit2,r) - query(bit1,l - 1) * (l - 1) - query(bit2,l - 1));
        }
    }
}
