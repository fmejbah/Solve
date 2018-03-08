#include <bits/stdc++.h>

using namespace std;

#define MAX 412345

struct node {
  int a[3], prop;
}tree[MAX];

void shift(int v) {
  int t = tree[v].a[0];
  tree[v].a[0] = tree[v].a[2];
  tree[v].a[2] = tree[v].a[1];
  tree[v].a[1] = t;
}

void init(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v].a[0] = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  int left = 2 * v;
  init(left, tl, tm);
  init(left + 1, tm + 1, tr);
  tree[v].a[0] = tree[left].a[0] + tree[left + 1].a[0];
}

void update(int v, int tl, int tr, int l, int r) {
  if (r < l) {
    return;
  }
  if (tl == l && tr == r) {
    //cout << tl << ' ' << tr << ' ' << tree[v].a[0] << ' ' << tree[v].a[1] << ' ' << tree[v].a[2] << endl;
    //cout << tree[v].prop << ' ';
    tree[v].prop = (tree[v].prop + 1) % 3;
    //cout << tree[v].prop << endl;;
    shift(v);
    //cout << tl << ' ' << tr << ' ' << tree[v].a[0] << ' ' << tree[v].a[1] << ' ' << tree[v].a[2] << endl;
    return;
  }
  int tm = (tl + tr) / 2;
  int left = 2 * v;
  if (r <= tm) {
    update(left, tl, tm, l, r);
  } else if (l > tm) {
    update(left + 1, tm + 1, tr, l, r);
  } else {
    update(left, tl, tm, l, min(tm, r));
    update(left + 1, tm + 1, tr, max(tm + 1, l), r);
  }
  for (int i = 0; i < 3; i++) {
    tree[v].a[i] = tree[left].a[i] + tree[left + 1].a[i];
  }
  if (tree[v].prop % 3 == 1) {
    shift(v);
  }
  if (tree[v].prop % 3 == 2) {
    shift(v);
    shift(v);
  }
}

int query(int v, int tl, int tr, int l, int r, int c = 0) {
  if (r < l) {
    return 0;
  }
  if (tl == l && tr == r) {
    if (c%3 == 1) {
      return tree[v].a[2];
    }
    if (c%3 == 2) {
      return tree[v].a[1];
    }
    return tree[v].a[0];
  }
  int tm = (tl + tr) >> 1;
  int left = v << 1;
  if (r <= tm) {
    return query(left, tl, tm, l, r, c + tree[v].prop);
  } else if (l > tm) {
    return query(left + 1, tm + 1, tr, l, r, c + tree[v].prop);
  } else {
    int r1 = query(left, tl, tm, l, min(tm, r), c + tree[v].prop);
    int r2 = query(left + 1, tm + 1, tr, max(tm + 1, l), r, c + tree[v].prop);
    return r1 + r2;
  }
}

void print(int n) {
  for (int i = 1; i <= 25; i++) {
    cout << i << ' ' << tree[i].a[0] << ' ' << tree[i].a[1] << ' ' << tree[i].a[2] << ' ' << tree[i].prop << endl;
  }
  puts("");
}
int main() {
  int T, n, q, t, i, j;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < MAX; i++) {
      tree[i].a[0] = tree[i].a[1] = tree[i].a[2] = 0;
      tree[i].prop = 0;
    }
    init(1, 1, n);
    printf("Case %d:\n", cn);
    while (q--) {
      scanf("%d%d%d", &t, &i, &j);
      i++, j++;
      if (t == 0) {
        update(1, 1, n, i, j);
//        puts("update"); print(n);
      } else {
        printf("%d\n", query(1, 1, n, i, j));
        //puts("query"); print(n);
      }
    }
  }
}
