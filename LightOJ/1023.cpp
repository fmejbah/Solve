#include <bits/stdc++.h>

using namespace std;

int T, N, K;
char s[27];
bool taken[27];

void permutation(int m) {
  if (!K) {
    return;
  }
  if (m == N) {
    if (K--) {
      printf("%s\n", s);
    }
    return;
  }
  for (int i = 0; i < N; i++) {
    if (!taken[i]) {
      taken[i] = 1;
      s[m] = 'A' + i;
      permutation(m + 1);
      taken[i] = 0;
      s[m] = '\0';
    }
  }
}

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &N, &K);
    memset(s, '\0', sizeof s);
    memset(taken, 0, sizeof taken);
    printf("Case %d:\n", cn);
    permutation(0);
  }
}
