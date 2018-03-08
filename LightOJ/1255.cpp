#include <bits/stdc++.h>

using namespace std;

const int sz = 1e6 + 3;

int T, pi[2 * sz], n, len, lenA, lenB;
char A[sz], B[2 * sz];

void prefixFunction() {
  int now;
  now = pi[0] = -1;
  for (int i = 1; i <= len; i++) {
    while (now != -1 && B[now + 1] != B[i]) {
      now = pi[now];
    }
    if (B[now + 1] == B[i]) {
      now++;
    } else {
      now = -1;
    }
    pi[i] = now;
    if (now + 1 == lenB) {
      n++;
    }
  }
}

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%s%s", A, B);
    lenA = strlen(A);
    lenB = strlen(B);
    len = lenA + lenB;
    B[lenB] = '#';
    for (int i = lenB + 1, j = 0; j < lenA; i++, j++) {
      B[i] = A[j];
    }
    n = 0;
    prefixFunction();
    printf("Case %d: %d\n", cn, n);
  }
}
