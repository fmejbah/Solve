#include <bits/stdc++.h>

using namespace std;

int t, r, c, a, x, d;

int main() {
  scanf("%d", &t);
  for (int cn = 1; cn <= t; cn++) {
    scanf("%d%d", &r, &c);
    a = 0;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%d", &x);
        d = r - i + c - j;
        if (d&1) {
          a ^= x;
        }
      }
    }
    printf("Case %d: ", cn);
    if (a) {
      puts("win");
    } else {
      puts("lose");
    }
  }
}
