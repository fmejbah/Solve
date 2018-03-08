#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
};

double cross_product(point a, point b) {
  return a.x * 1LL * b.y - a.y * 1LL * b.x;
}

double area(point vertices[], int n) {
  double A = 0.;
  for (int i = 0; i < n; i++) {
    A += cross_product(vertices[i], vertices[(i + 1) % n]);
  }
  return fabs(A) / 2.;
}

int main() {
  int T, n;
  long long int m, ans;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &n);
    point vertices[n];
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &vertices[i].x, &vertices[i].y);
    }
    double A = area(vertices, n);
    m = n;
    for (int i = 0, j = 1; i < n; i++, j = (j + 1) % n) {
      int x = vertices[i].x - vertices[j].x;
      int y = vertices[i].y - vertices[j].y;
      m += __gcd(abs(x), abs(y)) - 1;
    }
    //cout << A << ' ' << m << endl;
    ans = A + 1. - (m / 2.);
    printf("Case %d: %lld\n", cn, ans);
  }
}
