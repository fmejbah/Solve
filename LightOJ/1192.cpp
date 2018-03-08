#include <bits/stdc++.h>

using namespace std;

int T, k, a, b, c;

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &k);
    a = 0;
    for (int i = 0; i < k; i++) {
      scanf("%d%d", &b, &c);
      a ^= c - b - 1;
    }
    if (a) {
      printf("Case %d: Alice\n", cn);
    } else {
      printf("Case %d: Bob\n", cn);
    }
  }
}
