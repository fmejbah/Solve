#include <bits/stdc++.h>

using namespace std;

string s;
map<int, int> mp;

void multiply(int a) {
  int c = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    c += (s[i] - '0') * a;
    s[i] = (c % 10) + '0';
    c /= 10;
  }
  while (c) {
    s += (c % 10) + '0';
    c /= 10;
  }
}

void prime_factorization(int a) {
  for (int i = 2; i * i <= a; i++) {
    int n = 0;
    while (a % i == 0) {
      n++;
      a /= i;
    }
    if (mp.count(i)) {
      mp[i] = max(mp[i], n);
    } else if (n > 0) {
      mp[i] = n;
    }
  }
  if (a > 1 && !mp.count(a)) {
      mp[a] = 1;
  }
}

int main() {
  int T, n, a;
  scanf("%d", &T);
  for (int cn = 1; cn <= T; cn++) {
    scanf("%d", &n);
    mp.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", &a);
      prime_factorization(a);
    }
    s = "1";
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
      int m = it->second;
      a = it->first;
      for (int i = 0; i < m; i++) {
        multiply(a);
      }
    }
    printf("Case %d: ", cn);
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
}
