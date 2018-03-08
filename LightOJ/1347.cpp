#include <bits/stdc++.h>

using namespace std;

#define MAXN 112345
#define MAXM 17
#define mp(x, y) make_pair((x), (y))
#define xx first
#define yy second

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

char A[MAXN];
int P[MAXN][MAXM], N, M, lcp[MAXN], ranks[MAXN], tree[MAXN];
ppi L[MAXN];

void init(int v, int tl, int tr) {
  if (tr < tl) {
    return;
  }
  if (tl == tr) {
    tree[v] = lcp[tl];
    return;
  }
  int mid = (tl + tr) / 2;
  int left = 2 * v;
  init(left, tl, mid);
  init(left + 1, mid + 1, tr);
  tree[v] = min(tree[left], tree[left + 1]);
}

int min(int v, int tl, int tr, int lf, int rt) {
  if (tl == lf && tr == rt) {
    return tree[v];
  }
  int mid = (tl + tr) / 2;
  int left = 2 * v;
  if (rt <= mid) {
    return min(left, tl, mid, lf, rt);
  } else if (lf > mid) {
    return min(left + 1, mid + 1, tr, lf, rt);
  }
  int r0 = min(left, tl, mid, lf, min(mid, rt));
  int r1 = min(left + 1, mid + 1, tr, max(lf, mid + 1), rt);
  return min(r0, r1);
}
void SuffixArray() {
  for (int i = 0; i < N; i++) {
    P[i][0] = A[i] - 'a';
  }
  for (int j = 1; (1 << (j - 1)) < N; j++) {
    int l = 1 << (j - 1);
    for (int i = 0; i < N; i++) {
      L[i] = mp(mp(P[i][j - 1], (i + l < N) ? P[i + l][j - 1] : -1), i);
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
    now = max(now - 1, 0);
    if (P[i][M] == N - 1) {
      now = 0;
      continue;
    }
    int j = ranks[P[i][M] + 1];
    while (i + now < N && j + now < N && A[i + now] == A[j + now]) {
      now++;
    }
    lcp[P[i][M]] = now;
  }
  init(1, 0, N - 1);
}

int LCP(int i, int j) {
  /*
   * return ith suffix to jth suffix common prefix
   */
  //return min(1, 0, N - 1, i, j - 1);
  int x = ranks[i], y = ranks[j];
  if (x == y) {
    return N - x;
  }
  int ret = 0;
  for (int j = M; j >= 0 && x < N && y < N; j--) {
    if (P[x][j] == P[y][j]) {
      x += 1 << j;
      y += 1 << j;
      ret += 1 << j;
    }
  }
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    // Input
    scanf("%s", A); int a = strlen(A); A[a] = '#'; a++;
    scanf("%s", A + a); int b = strlen(A); A[b] = '$'; b++;
    scanf("%s", A + b); N = strlen(A); A[N] = '%'; N++;

    // Suffix Array and LCP
    SuffixArray();
    LCP();

    // Calculate substring
    int r = 0, i = 0, j = -1, x[] = {0, 0, 0};
    while (i < N || j < N) {
      while (x[0] < 1 || x[1] < 1 || x[2] < 1) {
        j++;
        if (j >= N) {
          break;
        }
        if (j == N) {
          break;
        }
        if (ranks[j] < a) {
          x[0]++;
        } else if (ranks[j] < b) {
          x[1]++;
        } else {
          x[2]++;
        }
      }
      while ((ranks[i] < a && x[0] - 1 > 0)
          || (ranks[i] >= a && ranks[i] < b && x[1] - 1 > 0)
          || (ranks[i] >= b && ranks[i] < N && x[2] - 1 > 0)) {
        if (ranks[i] < a) {
          x[0]--;
        } else if (ranks[i] < b) {
          x[1]--;
        } else {
          x[2]--;
        }
        i++;
        if (i >= N) {
          break;
        }
      }
      if (i >= 0 && i < N && j >= 0 && j < N) {
        r = max(r, LCP(i, j));
      }
      if (ranks[i] < a) {
        x[0]--;
      } else if (ranks[i] < b) {
        x[1]--;
      } else {
        x[2]--;
      }
      i++;
    }

    // Print output
    printf("Case %d: %d\n", cn, r);
  }
}
