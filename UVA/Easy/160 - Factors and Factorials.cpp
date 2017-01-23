#include <bits/stdc++.h>

using namespace std;

int main() {
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    map<int,int> indx;
    for( int i = 0; i < 25; i++ ) {
        indx[prime[i]] = i;
    }
    vector<int> v[101];
    v[2].push_back(1);

    for( int i = 3; i <= 100; i++ ) {
        v[i] = v[i-1];
        int n = i;
        while( n%2 == 0 ) {
            v[i][0]++;
            n /= 2;
        }

        for( int j = 3; j <= n; j += 2 ) {
            while( n%j == 0 ) {
                if( indx[j] >= v[i].size() ) {
                    v[i].push_back(1);
                } else {
                    v[i][indx[j]]++;
                }
                n /= j;
            }
        }
    }

    int x;
    while(true) {
        cin >> x;
        if( x == 0 ) {
            return 0;
        }
        printf("%3d! =", x);
        for( int i = 0; i < v[x].size(); i++ ) {
            if( i == 15 ) {
                printf("\n      %3d", v[x][i]);
            } else {
                printf("%3d", v[x][i]);
            }
        }
        cout << endl;
    }
}

