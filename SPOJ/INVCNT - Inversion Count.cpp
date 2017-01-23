/*###########################################
 *                                          #
 * fb.com/mfmejbah                          #
 * fmejbah@gmail.com                        #
 * SPOJ: INVCNT - Inversion Count           #
 * Inversions: Merge Sort                   #
 * 3/7/15                                   #
 *###########################################
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

i64 ary[200003], aux[200003], invns;

void Merging( i64 l, i64 m, i64 r )
{
    i64 i, j, k;
    for( i = l; i <= r; i++ )
        aux[i] = ary[i];

    i = l;
    j = m + 1;
    for( k = l; k <= r; k++ )
    {
        if( i > m )
            ary[k] = aux[j++];
        else if( j > r )
            ary[k] = aux[i++];
        else if( aux[i] <= aux[j] )
            ary[k] = aux[i++];
        else
            ary[k] = aux[j++], invns += m-i+1;
    }
}

void MergeSort( i64 lo, i64 hi )
{
    if( lo < hi )
    {
        i64 m = (lo+hi)/2;
        MergeSort(lo,m);
        MergeSort(m+1,hi);
        Merging(lo,m,hi);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    i64 t, n;

    cin >> t;
    while(t--)
    {
        cin >> n;
        for( i64 i = 0; i < n; i++ )
            cin >> ary[i];
        invns = 0;
        MergeSort(0,n-1);
        cout << invns << endl;
    }
}
