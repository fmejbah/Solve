/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 13089
 * Date: 07 Nov 2016
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> G[1001];
int dis[1001];
bool vis[1001];

void bfs( int s ) {
  memset(vis, 0, sizeof(vis));
  queue<int> Q;
  Q.push(s);
  vis[s] = 1;
  dis[s] = 0;
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for( int i = 0; i < G[u].size(); i++ ) {
      int v = G[u][i];
      if(!vis[v]) {
        vis[v] = 1;
        dis[v] = 1 + dis[u];
        Q.push(v);
      }
    }
  }
}

int main()
{
  //freopen("13089.in", "r", stdin);
  //freopen("13089.out", "w", stdout);
  int T; cin >> T;
  for( int cn = 1; cn <= T; cn++ ) {
    int n; cin >> n;
    int coin[1001];
    for( int i = 1; i <= n; i++ )
      cin >> coin[i];
    for( int i = 1; i < n; i++ ) {
      int u, v; cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    int ans = 0;
    for( int s = 1; s <= n; s++ ) {
      bfs(s);
      int x = 0;
      for( int i = 1; i <= n; i++ )
        if(coin[i]&1) x ^= dis[i];
      if(!x) ans++;
    }
    printf("Case %d: %d\n", cn, ans);
    for( int i = 0; i < 1001; i++ )
      G[i].clear();
  }
}
