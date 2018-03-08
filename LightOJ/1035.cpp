#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, n, a[100];
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &n);
    memset(a, 0, sizeof a);
    for(int i = 2; i <= n; i++) {
      int x = i;
      for (int j = 2; j * j <= x; j++) {
        while (x % j == 0) {
          a[j]++;
          x /= j;
        }
      }
      if (x > 1) {
        a[x]++;
      }
    }
    printf("Case %d: %d = 2 (%d)", cn, n, a[2]);
    for (int i = 3; i <= n; i += 2) {
      if (a[i]) {
        printf(" * %d (%d)", i, a[i]);
      }
    }
    puts("");
  }
}
