#include <bits/stdc++.h>

using namespace std;

int T;
double l, w, x;

double f(double xx) {
  return (l - 2 * xx) * (w - 2 * xx) * xx;
}

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%lf%lf", &l, &w);
    x = (l + w - sqrt(l*l - l * w + w * w)) / 6;
    printf("Case %d: %.10f\n", cn, f(x));
  }
}
