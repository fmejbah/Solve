/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 1085 - All Possible Increasing Subsequences.cpp
 * Date: 23 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 123456;
const int mod = 1e9 + 7;

int n, sequence[N], fenwick[N];

void update(int idx, int val) {
	while (idx <= n) {
		fenwick[idx] += val;
		fenwick[idx] %= mod;
		idx += idx & -idx;
	}
}

int read(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += fenwick[idx];
		sum %= mod;
		idx -= idx & -idx;
	}
	return sum;
}

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int solve() {
	memset(fenwick, 0, sizeof fenwick);
	pair<int, int> A[n];
	for (int i = 0; i < n; i++) {
		A[i].first = sequence[i];
		A[i].second = i;
	}
	sort(A, A+n, comp);
	for (int i = 0; i < n; i++) {
		vector<pair<int, int> > v;
		while (i + 1 < n && A[i].first == A[i+1].first) {
			v.push_back(make_pair(A[i].second + 1, 1 + read(A[i].second)));
			i++;
		}
		v.push_back(make_pair(A[i].second + 1, 1 + read(A[i].second)));
		for (int j = 0; j < (int)v.size(); j++)
			update(v[j].first, v[j].second);
	}
	return read(n);
}

int main() {
//	freopen("out.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int cn = 1; cn <= T; cn++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", sequence + i);
		}
		printf("Case %d: %d\n", cn, solve());
	}
}
