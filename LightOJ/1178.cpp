#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  double a, b, c, d, x, h;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    if (a < c) {
      swap(a, c);
    }
    x = a - c;
    if (b < d) {
      swap(b, d);
    }
    x = (x * x + b * b - d * d) / (2 * x);
    h = sqrt(b * b - x * x);
    printf("Case %d: %f\n", cn, .5 * (a + c) * h);
  }
}
