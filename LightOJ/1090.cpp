#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, n, r, p, q, n_r, two, five, m;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d%d%d", &n, &r, &p, &q);
    two = five = 0;
    n_r = n - r;
    while (p % 2 == 0) {
      two++;
      p /= 2;
    }
    while (p % 5 == 0) {
      five++;
      p /= 5;
    }
    two *= q;
    five *= q;
    for (int i = 2; n / i > 0; i *= 2) {
      two += n / i;
    }
    for (int i = 5; n / i > 0; i *= 5) {
      five += n / i;
    }
    for (int i = 2; r / i > 0; i *= 2) {
      two -= r / i;
    }
    for (int i = 5; r / i > 0; i *= 5) {
      five -= r / i;
    }
    for (int i = 2; n_r / i > 0; i *= 2) {
      two -= n_r / i;
    }
    for (int i = 5; n_r / i > 0; i *= 5) {
      five -= n_r / i;
    }
    printf("Case %d: %d\n", cn, min(two, five));
  }
}
