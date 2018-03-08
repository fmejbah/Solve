#include <bits/stdc++.h>

using namespace std;

const int sz = 1e6 + 3;

int T, pi[sz], len, n, now;
char s[sz], rs[sz];

void prefixFunction() {
  now = pi[0] = -1;
  for(int i = 1; i < len; i++) {
    while (now != -1 && rs[now + 1] != rs[i]) {
      now = pi[now];
    }
    if (rs[now + 1] == rs[i]) {
      now++;
    } else {
      now = -1;
    }
    pi[i] = now;
  }
}

void kmp() {
  prefixFunction();
  now = -1;
  for (int i = 0; i < len; i++) {
    while (now != -1 && rs[now + 1] != s[i]) {
      now = pi[now];
    }
    if (rs[now + 1] == s[i]) {
      now++;
    } else {
      now = -1;
    }
  }
}

int main() {
  scanf("%d", &T);
  for(int cn = 1; cn <= T; cn++) {
    scanf("%s", s);
    len = strlen(s);
    for (int i = 0, j = len - 1; i < len; i++, j--) {
      rs[i] = s[j];
    }
    kmp();
    printf("Case %d: %d\n", cn, 2 * len - now - 1);
  }
}
