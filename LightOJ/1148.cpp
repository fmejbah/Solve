#include <bits/stdc++.h>

using namespace std;

int T, n, x, ans;
map<int, int> mp;

int main() {
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &n);
    ans = 0;
    while (n--) {
      scanf("%d", &x);
      if (mp.count(x)) {
        mp[x]++;
      } else {
        mp[x] = 1;
      }
    }
    for (map<int, int>::iterator a = mp.begin(); a != mp.end(); a++) {
      ans += ceil(a->second / (a->first + 1.)) * (a->first + 1);
    }
    printf("Case %d: %d\n", cn, ans);
    mp.clear();
  }
}
