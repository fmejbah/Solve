#include <bits/stdc++.h>

using namespace std;

#define MAXN  51234
#define MAXG  16
#define mp(x, y) make_pair((x), (y))
#define xx first
#define yy second

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

int T, N, M, sl, bl, lcp[MAXN], P[MAXN][MAXG], ranks[MAXN], pi[MAXN];
ppi L[MAXN];
char A[MAXN], B[MAXN], s[2 * MAXN];
vector<int> v;
LL ans;

void SuffixArray() {
  for (int i = 0; i < N; i++) {
    P[i][0] = A[i] - 'a';
  }
  for (int j = 1; (1 << (j - 1)) < N; j++) {
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
  int now = 0;
  for (int i = 0; i < N; i++) {
    ranks[P[i][M]] = i;
  }
  for (int i = 0; i < N; i++) {
    if (P[i][M] == N - 1) {
      now = 0;
      continue;
    }
    now = max(0, now - 1);
    int j = ranks[P[i][M] + 1];
    while (now + i < N && now + j < N && A[i + now] == A[j + now]) {
      now++;
    }
    lcp[P[i][M]] = now;
  }
}

void prefixFunction() {
  int now;
  pi[0] = now = -1;
  for (int i = 1; i < sl; i++) {
    while (now != -1 && s[now + 1] != s[i]) {
      now = pi[now];
    }
    if (s[now + 1] == s[i]) {
      now++;
    } else {
      now = -1;
    }
    pi[i] = now;
    if (pi[i] == bl - 1) {
      // start index
      v.push_back(i - pi[i] - bl - 1);
      //v.push_back(i - pi[i] - 2);
    }
  }
}

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%s%s", A, B);
    N = strlen(A);
    bl = strlen(B);
    sl = 0;
    for (int i = 0; i < bl; i++) {
      s[sl++] = B[i];
    }
    s[sl++] = '#';
    for (int i = 0; i < N; i++) {
      s[sl++] = A[i];
    }
    prefixFunction();
    SuffixArray();
    LCP();
    int st = ranks[0];
    if (N == 1) {
      st = 0;
    }
    int end = lower_bound(v.begin(), v.end(), st) - v.begin();
    if (end == (int)v.size()) {
      end = N;
    } else {
      end = v[end] + bl - 1;
    }
    ans = end - st;
    /*
    for (int j = st; j < N; j++) { cout << A[j]; } puts("");
    cout << st << ' ' << end << endl;
    cout << ans << endl;
    */
    for (int i = 1; i < N; i++) {
      int st = ranks[i];
      int end = lower_bound(v.begin(), v.end(), st) - v.begin();
      if (end == (int)v.size()) {
        end = N;
      } else {
        end = v[end] + bl - 1;
      }
      ans += max(0, end - st - lcp[i - 1]);
      /*
      for (int j = st; j < N; j++) { cout << A[j]; } puts("");
      cout << st << ' ' << end << ' ' << lcp[i - 1] << endl;
      cout << ans << endl;
      */
    }
    printf("Case %d: %d\n", cn, ans);
    //for (int i = 0; i < v.size(); i++) { cout << v[i] << ' '; } puts("");
    v.clear();
  }
}
