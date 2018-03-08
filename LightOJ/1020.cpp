#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, n;
  char s[11];
  scanf("%d", &T);
  for(int cn = 1; cn <= T; cn++) {
    scanf("%d%s", &n, s);
    printf("Case %d: ", cn);
    if (s[0] == 'A') {
      if (n % 3 == 1) {
        puts("Bob");
      } else {
        puts("Alice");
      }
    } else {
      if (n % 3) {
        puts("Bob");
      } else {
        puts("Alice");
      }
    }
  }
}
