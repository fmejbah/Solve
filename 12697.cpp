/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 12697.cpp
 * Date: 08 Mar 2017
 */

#include <bits/stdc++.h>

using namespace std;

#define xx first
#define yy second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(), (x).end()
#define mem(x,y) memset(x, y, sizeof(x))

typedef long long int int64;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef map<string, int> msi;

const int mod = 1e9 + 7;
const double PI = acos(-1.0);
int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};

template < class T > T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template < class T > T lcm(T a, T b) { return a / gcd(a, b) * b; }
template < class T > T pow(T a, T b) { T r = 1; while(b > 0) { if(b & 1) r = r * a; a = a * a; b /= 2; } return r; }
template < class T > T pow(T a, T b, T mod) { T r = 1; while(b > 0) { if(b & 1) r = r * a % mod; a = a * a % mod; b /= 2; } return r; }
bool comp( pii a, pii b ) { if( a.xx == b.xx ) return a.yy > b.yy; return a.xx < b.xx; }


inline int Set(int N, int pos) { return N |= 1 << pos; }
inline int reset(int N, int pos) { return N &= ~(1 << pos); }
inline bool on(int N, int pos) { return (bool)(N & (1 << pos)); }

struct data {
  int indx;
  int64 val, aux;
}d;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int N, X;
    scanf("%d%d", &N, &X);
    int a[N];
    for (int i = 0; i < N; i++) {
      scanf("%d", a + i);
    }
    deque<data> dq;
    d.indx = 0;
    d.val = a[0];
    d.aux = 0;
    dq.push_front(d);
    for (int i = 1; i < N; i++) {
      while (!dq.empty() && dq.front().val + a[i] <= a[i]) {
        d = dq.front();
        dq.pop_front();
        if(!dq.empty()) {
          dq.front().aux += d.aux;
          dq.front().val += d.aux;
        }
      }
      d.indx = i;
      d.val = a[i];
      d.aux = a[i];
      dq.push_front(d);
    }
    for (deque<data>::iterator i = dq.begin(); i != dq.end(); i++) {
      cout << i->indx << ' ' << i->val << ' ' << i->aux << endl;
    }
  }
}
