#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  int x1, y1, r1, x2, y2, r2;
  double d, x, y, l, A1, A2;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d%d", &x1, &y1, &r1);
    scanf("%d%d%d", &x2, &y2, &r2);
    x2 -= x1;
    y2 -= y1;
    d = sqrt((x2 * x2) + (y2 * y2) + 0.0);
    //printf("d: %.10f %d %f\n", d, r1 + r2, d - r1 - r2);
    if (d - r1 - r2 >= -0.00000001) {
      printf("Case %d: %.10f\n", cn, 0.0);
      continue;
    }
    if (r1 > r2) {
      swap(r1, r2);
    }
    if (d + r1 <= r2) {
      printf("Case %d: %.10f\n", cn, acos(-1.0) * r1 * r1);
      continue;
    }
    x = (d * d + r1 * r1 - r2 * r2) / (2 * d);
    l = sqrt(r1 * r1 - x * x);
    //cout << x << ' ' << l << endl;
    A1 = r1 * r1 * acos(x / r1) - l * x;
    A2 = r2 * r2 * acos((d - x) / r2) - l * (d - x);
    printf("Case %d: %.10f\n", cn, A1 + A2);
  }
}
