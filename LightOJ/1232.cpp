#include <bits/stdc++.h>

using namespace std;

const int mod = 100000007;

int T, n, k, A[123], ways[11234];

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", A + i);
    }
    memset(ways, 0, sizeof ways);
    ways[0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        if (ways[j] && j + A[i] <= k) {
          ways[j + A[i]] += ways[j];
          ways[j + A[i]] %= mod;
        }
      }
    }
    printf("Case %d: %d\n", cn, ways[k]);
  }
}
