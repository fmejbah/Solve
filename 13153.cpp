/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 13153 - Number of Connected Components.cpp
 * Date: 26 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;

int marked[N / 64 + 1];

inline bool isOn(int x) { return (marked[x / 64] & (1 << ((x%64)/2))); }
inline void mark(int x) { (marked[x / 64] |= (1 << ((x%64)/2))); }

vector<int> primes;

void sieve() {
	for (int i = 3; i * i < N; i += 2)
		if (!isOn(i))
			for (int j = i * i; j < N; j += i + i)
				mark(j);
	primes.push_back(2);
	for (int i = 3; i < N; i += 2)
		if (!isOn(i))
			primes.push_back(i);
}

vector<int> G[1000001];
bool visited[1000001];

void dfs(int u) {
	visited[u] = 1;
	for (int i = 0; i < (int)G[u].size(); i++)
		if (!visited[G[u][i]]) {
			dfs(G[u][i]);
		}
}

int main() {
  freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	sieve();
	int T; scanf("%d", &T);
	for (int cn = 1; cn <= T; cn++) {
		int n; scanf("%d", &n);
		int ans = 0, x;
		bool A[1000001];
		memset(A, 0, sizeof A);
		set<int> s;
		for (int i = 0; i < n; i++) {
			bool f = 0;
			scanf("%d", &x);
			if (x == 1) {
				ans++;
				continue;
			}
			for (int j = 0; j < (int)primes.size(); j++)
				if (x % primes[j] == 0) {
					G[x].push_back(primes[j]);
					G[primes[j]].push_back(x);
					f = 1;
					A[x] = 1;
					A[primes[j]] = 1;
				}
			if (!f) s.insert(x);
		}
		ans += (int) s.size();
		memset(visited, 0, sizeof visited);
		for (int i = 1; i <= 1000000; i++)
			if (A[i] && !visited[i]) {
				dfs(i);
				ans++;
			}
		for (int i = 1; i <= 1000000; i++)
			G[i].clear();
		printf("Case %d: %d\n", cn, ans);
	}
}
