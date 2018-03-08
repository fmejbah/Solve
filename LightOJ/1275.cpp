#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, N, C, ans;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &N, &C);
    if (N == 0) {
      ans = 0;
    } else {
      ans = C / (2. * N) + .49;
    }
    printf("Case %d: %d\n", cn, ans);
  }
}
