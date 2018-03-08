#include <bits/stdc++.h>

using namespace std;

#define MAX 51234
#define xx first
#define yy second

typedef pair<int, int> point;

point a[MAX], c[MAX];
int b[MAX];

int main() {
  int T, n, q;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a[i].xx, &a[i].yy);
    }
    sort(a, a + n);
    /*
    for (int i = 0; i < n; i++) {
      cout << a[i].xx << ' ' << a[i].yy << endl;
    }
    */
    for (int i = 0; i < q; i++) {
      scanf("%d", b + i);
      c[i].xx = b[i];
      c[i].yy = i;
    }
    sort(c, c + q);
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0, j = 0; i < q; i++) {
      //cout << c[i].xx << ' ' << c[i].yy << endl;
      while (j < n && a[j].xx <= c[i].xx) {
        if (a[j].yy >= c[i].xx) {
          pq.push(a[j].yy);
          //cout << "in: " << a[j].xx << endl;
        }
        j++;
      }
      while (!pq.empty() && pq.top() < c[i].xx) {
        pq.pop();
      }
      b[c[i].yy] = pq.size();
    }
    printf("Case %d:\n", cn);
    for (int i = 0; i < q; i++) {
      printf("%d\n", b[i]);
    }
  }
}
