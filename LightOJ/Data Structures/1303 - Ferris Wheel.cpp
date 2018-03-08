/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 1303 - Ferris Wheel.cpp
 * Date: 23 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("out.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int cn = 1; cn <= T; cn++) {
		int n, m; scanf("%d%d", &n, &m);
		deque<int> dq;
		for (int i = 1; i <= n; i++)
			dq.push_back(i);
		int i = 0, w[m];
		set<int> s[n+1];
		memset(w, -1, sizeof w);
		while (1) {
			int p = i % m;
			if (w[p] != -1) {
				if(s[w[p]].size() < m) {
					dq.push_back(w[p]);
				}
				w[p] = -1;
			}
			stack<int> st;
			while (!dq.empty()) {
				int x = dq.front();
				dq.pop_front();
				if (s[x].find(p) == s[x].end()) {
					w[p] = x;
					s[x].insert(p);
					break;
				}
				st.push(x);
			}
			while (!st.empty()) {
				dq.push_front(st.top());
				st.pop();
			}
			int a = 0, b = 0;
			for (int l = 1; l <= n; l++)
				if (s[l].size() == m) a++;
			for (int l = 0; l < m; l++)
				if (w[l] == -1) b++;
			if (a == n && b == m) break;
			i++;
		}
		printf("Case %d: %d\n", cn, 5 * (i + 1));
	}
}
