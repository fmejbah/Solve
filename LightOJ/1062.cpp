#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  double x, y, c, a, b, cc, h1, h2, wl, wh, w;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%lf%lf%lf", &x, &y, &c);
    wl = 0, wh = min(x, y);
    for (int i = 0; i < 100; i++) {
      w = (wl + wh) / 2;
      h1 = sqrt(x * x - w * w);
      h2 = sqrt(y * y - w * w);
      a = (x * h2) / (h1 + h2);
      b = a * w / x;
      cc = sqrt(a * a - b * b);
      if (cc - c > 0) {
        wl = w;
      } else {
        wh = w;
      }
    }
    printf("Case %d: %.10f\n", cn, w);
  }
}
