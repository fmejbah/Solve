#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, p, l;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &p, &l);
    vector<int> v0, v1;
    p -= l;
    int a = 0;
    for (int i = 1; i * 1LL * i <= p; i++) {
      if (i * i == p && i > l) {
        v0.push_back(i);
        a++;
      } else if (p % i == 0) {
        if (i > l) {
          v0.push_back(i);
          a++;
        }
        if (p / i > l) {
          v1.push_back(p / i);
          a++;
        }
      }
    }
    printf("Case %d:", cn);
    if (a == 0) {
      puts(" impossible");
    } else {
      for (int i = 0; i < (int)v0.size(); i++) {
        printf(" %d", v0[i]);
      }
      for (int i = (int)v1.size() - 1; i >= 0; i--) {
        printf(" %d", v1[i]);
      }
      puts("");
    }
  }
}
