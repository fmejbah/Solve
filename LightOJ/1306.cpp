#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int extended_euclid(int a, int b, LL &x, LL &y) {
  LL xx = y = 0;
  LL yy = x = 1;
  while (b) {
    int q = a / b;
    int t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}

/*
 * Find any solution of 
 * Ax + By = C
 */
bool find_any_solution(int a, int b, int c, LL &x, LL &y, int &g) {
  g = extended_euclid(abs(a), abs(b), x, y);
  if (c % g != 0) {
    return false;
  }
  x *= c / g;
  y *= c / g;
  if (a < 0) {
    x *= -1;
  }
  if (b < 0) {
    y *= -1;
  }
  return true;
}

void shift_solution(LL &x, LL &y, int a, int b, int k) {
  x += k * 1LL * b;
  y -= k * 1LL * a;
}

LL calculate(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
  c *= -1;
  if (a == 0 && b == 0) {
    if (c == 0) {
      return (maxx - minx + 1LL) * (maxy - miny + 1LL);
    }
    return 0;
  }
  if (a == 0) {
    int z = c / b;
    if (c % b == 0 && z >= miny && z <= maxy) {
      return maxx - minx + 1;
    }
    return 0;
  }
  if (b == 0) {
    int z = c / a;
    if (c % a == 0 && z >= minx && z <= maxx) {
      return maxy - miny + 1;
    }
    return 0;
  }
  LL x, y, x0, y0;
  int g;
  if (!find_any_solution(a, b, c, x, y, g)) {
    return 0;
  }
  x0 = x, y0 = y;
  a /= g;
  b /= g;
  int sign_a = a < 0 ? -1 : 1;
  int sign_b = b < 0 ? -1 : 1;
  int kxl = (minx - x) / b;
  shift_solution(x, y, a, b, kxl);
  if (x < minx) {
    shift_solution(x, y, a, b, sign_b);
    kxl += sign_b;
  }
  if (x > maxx) {
    return 0;
  }
  x = x0, y = y0;
  int kxr = (maxx - x) / b;
  shift_solution(x, y, a, b, kxr);
  if (x > maxx) {
    shift_solution(x, y, a, b, -sign_b);
    kxr -= sign_b;
  }
  x = x0, y = y0;
  int kyl = (y - miny) / a;
  shift_solution(x, y, a, b, kyl);
  if (y < miny) {
    shift_solution(x, y, a, b, -sign_a);
    kyl -= sign_a;
  }
  if (y > maxy) {
    return 0;
  }
  x = x0, y = y0;
  int kyr = (y - maxy) / a;
  shift_solution(x, y, a, b, kyr);
  if (y > maxy) {
    shift_solution(x, y, a, b, sign_a);
    kyr += sign_a;
  }
  if (kxl > kxr) {
    swap(kxl, kxr);
  }
  if (kyl > kyr) {
    swap(kyl, kyr);
  }
  int kl = max(kxl, kyl);
  int kr = min(kxr, kyr);
  return max(0, kr - kl + 1);
}

int main() {
  int T, A, B, C, minx, miny, maxx, maxy;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d%d%d%d%d%d", &A, &B, &C, &minx, &maxx, &miny, &maxy);
    printf("Case %d: %lld\n", cn, calculate(A, B, C, minx, maxx, miny, maxy));
  }
}
