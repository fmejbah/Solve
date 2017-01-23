/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 1080 - Binary Simulation
 * Date: 23 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

int n, fenwick[100003];

void update(int idx, int val) {
	while (idx <= n) {
		fenwick[idx] += val;
		idx += idx & -idx;
	}
}

int read(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += fenwick[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main()
{
	int T; scanf("%d", &T);
	for (int cn = 1; cn <= T; cn++) {
		string s; cin >> s;
		n = s.length();
		memset(fenwick, 0, sizeof fenwick);
		for (int i = 0; i < s.length(); i++)
			if (s[i] == '1') {
				update(i+1, 1);
				update(i+2, -1);
			}
		int q; scanf("%d", &q);
		printf("Case %d:\n", cn);
		while (q--) {
			char c; scanf(" %c ", &c);
			if (c == 'I') {
				int i, j; scanf("%d%d", &i, &j);
				update(i, 1);
				update(j+1, -1);
			} else {
				int i; scanf("%d", &i);
				printf("%d\n", read(i)&1);
			}
		}
	}
}
