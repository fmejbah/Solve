#include <bits/stdc++.h>

using namespace std;

const int mod = 100000007;

int T, N, K, S, A[3][15123], sum[15123];

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d%d", &N, &K, &S);
    A[1][0] = 0;
    for (int i = 1; i <= S; i++) {
      A[1][i] = (i <= K) ? 1 : 0;
    }
    for (int i = 1; i < N; i++) {
      sum[0] = 0;
      for (int j = 1; j <= S; j++) {
        sum[j] = (A[i % 2][j] + sum[j - 1]) % mod;
        A[(i + 1) % 2][j] = (sum[j - 1] - sum[max(0, j - K - 1)] + mod) % mod;
      }
    }
    printf("Case %d: %d\n", cn, A[N % 2][S]);
  }
}
/*
  0 1 2 3 4 5 6 7 8 9 10
0 0 0 0 0 0 0 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 0
2 0 0 1 2 
3 0
4 0
5 0
*/
