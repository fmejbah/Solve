#include <bits/stdc++.h>

using namespace std;

const int sz = 1e6 + 3;

int pi[sz], now, len, a, x;
char s[sz];

void prefixFunction() {
  now = pi[0] = -1;
  for (int i = 1; i < len; i++) {
    while (now != -1 && s[now + 1] != s[i]) {
      now = pi[now];
    }
    if (s[now + 1] == s[i]) {
      now++;
    } else {
      now = -1;
    }
    pi[i] = now;
  }
}

int main() {
  while (scanf("%s", s) == 1) {
    if (s[0] == '.') {
      return 0;
    }
    len = strlen(s);
    prefixFunction();
    x = len - pi[len - 1] - 1;
    if (len % x == 0) {
      a = len / x;
    } else {
      a = 1;
    }
    printf("%d\n", a);
  }
}
