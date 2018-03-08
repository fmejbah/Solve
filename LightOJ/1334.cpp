#include <bits/stdc++.h>

using namespace std;

const int MAX = 51234;

int T, pi[2 * MAX], N, M, dl, gl, A[MAX], B[MAX];
long long int ans, a[MAX], b[MAX];
char s[2 * MAX], g[MAX], d[MAX];

void prefixFunction() {
  int now;
  pi[0] = now = -1;
  for (int i = 1; i < N; i++) {
    while (now != -1 && s[now + 1] != s[i]) {
      now = pi[now];
    }
    if (s[now + 1] == s[i]) {
      pi[i] = ++now;
    } else {
      pi[i] = now = -1;
    }
  }
}

void createString() {
  N = 0;
  for (int i = 0; i < gl - 1; i++) {
    s[N++] = g[i];
  }
  s[N++] = '#';
  for (int i = 0; i < dl; i++) {
    s[N++] = d[i];
  }
}

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%s%s", d, g);
    dl = strlen(d);
    gl = strlen(g);
    createString();
    prefixFunction();
    M = 0;
    for (int i = 0; i < gl; i++) {
      a[i] = b[i] = 1;
    }
    for (int i = 0; i < gl; i++) {
      if (pi[i] >= 0) {
        a[i] += a[pi[i]];
      }
    }
    for (int i = gl; i < N; i++) {
      A[M++] = pi[i];
    }
    reverse(d, d + dl);
    reverse(g, g + gl);
    createString();
    prefixFunction();
    for (int i = 0; i < gl; i++) {
      if (pi[i] >= 0) {
        b[i] += b[pi[i]];
      }
    }
    for (int i = gl, j = 0; i < N; i++) {
      B[j++] = pi[i];
    }
    reverse(B, B + M);
    ans = 0;
    for (int i = 0; i < M - 1; i++) {
      if (A[i] >= 0 && B[i + 1] >= 0) {
        ans += a[A[i]] * 1LL * b[B[i + 1]];
      }
    }
    printf("Case %d: %lld\n", cn, ans);
  }
}
