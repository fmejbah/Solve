#include <bits/stdc++.h>

using namespace std;

int T, n, b[123], w, a;

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", b + i);
    }
    a = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &w);
      a ^= w - b[i] - 1;
    }
    printf("Case %d: ", cn);
    if (a) {
      puts("white wins");
    } else {
      puts("black wins");
    }
  }
}
