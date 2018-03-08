#include <bits/stdc++.h>

using namespace std;

#define xx first
#define yy second
#define mp(x, y) make_pair(x, y)
#define MAXN 112345
#define MAXM 17

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

char s[MAXN];
int T, N, i, j, l, r, P[MAXN][MAXM];
ppi L[MAXN];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s", &N, s);
    for (i = 0; i < N; i++) {
      P[i][0] = s[i] - 'a';
    }
    for (j = 1; (1 << j) < N; j++) {
      l = 1 << (j - 1);
      for (i = 0; i < N; i++) {
        L[i] = mp(mp(P[i][j - 1], P[(i + l) % N][j - 1]), i);
      }
      //sort(L, L + N);
      stable_sort(L, L + N);
      r = 0;
      P[L[0].yy][j] = r;
      for (i = 1; i < N; i++) {
        if (L[i].xx != L[i - 1].xx) {
          r++;
        }
        P[L[i].yy][j] = r;
      }
    }
    l = P[0][j - 1], r = 0;
    for (i = 1; i < N; i++) {
      if (P[i][j - 1] < l) {
        l = P[i][j - 1];
        r = i;
      }
    }
    printf("%d\n", r);
  }
}
