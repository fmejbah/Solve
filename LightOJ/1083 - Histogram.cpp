#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    stack<int> indx;
    int mx = 0;
    for (int i = 0; i < n; ) {
      if (indx.empty() || a[indx.top()] <= a[i]) {
        indx.push(i++);
      } else {
        int top = indx.top();
        indx.pop();
        mx = max(mx, a[top] * (indx.empty() ? i : i - top));
      }
    }
    while (!indx.empty()) {
      int top = indx.top();
      indx.pop();
      mx = max(mx, a[top] * (indx.empty() ? n : n - top));
    }
    printf("Case %d: %d\n", cn, mx);
  }
}
