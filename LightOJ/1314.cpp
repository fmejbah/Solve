#include <bits/stdc++.h>

using namespace std;

#define MAXN 16384
#define MAXG 14
#define mp(x, y) make_pair(x, y)
#define xx first
#define yy second

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

int T, p, q, N, M, P[MAXN][MAXG], lcp[MAXN], ranks[MAXN];
ppi L[MAXN];
char s[MAXN];

void suffixArray() {
  for (int i = 0; i < N; i++) {
    P[i][0] = s[i] - 'a';
  }
  for (int j = 1; (1 << (j - 1)) <= N; j++) {
    int l = 1 << (j - 1);
    for (int i = 0; i < N; i++) {
      L[i] = mp(mp(P[i][j - 1], (i + l) < N ? P[i + l][j - 1] : -1), i);
    }
    sort(L, L + N);
    int r = 0;
    P[L[0].yy][j] = r;
    for (int i = 1; i < N; i++) {
      if (L[i].xx != L[i - 1].xx) {
        r++;
      }
      P[L[i].yy][j] = r;
    }
    M = j;
  }
}

void LCP() {
  for (int i = 0; i < N; i++) {
    ranks[P[i][M]] = i;
  }
  int now = 0;
  for (int i = 0; i < N; i++) {
    now = max(0, now - 1);
    if (P[i][M] == N - 1) {
      now = 0;
      continue;
    }
    int j = ranks[P[i][M] + 1];
    while (i + now < N && j + now < N && s[i + now] == s[j + now]) {
      now++;
    }
    lcp[P[i][M]] = now;
  }
}

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%s%d%d", s, &p, &q);
    N = strlen(s);
    suffixArray();
    LCP();
    /*
    puts("====P=======");
    for (int i = 0; i < N; i++) {
      cout << i;
      for (int j = 0; j <= M; j++) {
        cout << ' ' << P[i][j];
      } puts("");
    }
    puts("====ranks====");
    for (int i = 0; i < N; i++) {
      cout << i << ' ' << ranks[i] << endl;
    }
    puts("====LCP====");
    for (int i = 0; i < N - 1; i++) {
      cout << i << ' ' << lcp[i] << endl;
    }
    cout << N << endl;
    */
    int ans = max(0, min(N - ranks[0], q) - p + 1);
    for (int i = 1; i < N; i++) {
      int l = N - ranks[i];
      if (l < p || lcp[i - 1] > q) {
        continue;
      }
      if (l > q) {
        l = q;
      }
      if (lcp[i - 1] >= p) {
        l -= lcp[i - 1];
      } else {
        l -= p - 1;
      }
      ans += l;
    }
    printf("Case %d: %d\n", cn, ans);
  }
}
