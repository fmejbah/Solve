#include <bits/stdc++.h>

using namespace std;

#define MAX 11234
#define xx first
#define yy second

typedef pair<int, int> pii;

pii b[MAX];
double ans[MAX];

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d", &b[i].xx);
    b[i].yy = i;
  }
  sort(b + 1, b + T + 1);
  double h = 0;
  b[0].xx = 0;
  for (int i = 1; i <= T; i++) {
    for (int j = b[i - 1].xx + 1; j <= b[i].xx; j++) {
      h += 1. / j;
    }
    ans[b[i].yy] = h;
  }
  for (int cn = 1; cn <= T; cn++) {
    printf("Case %d: %.10f\n", cn, ans[cn]);
  }
}
