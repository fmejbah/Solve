/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * MSE06H.cpp
 * Date: 23 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

struct data {
	int e, w;
	bool operator<(const data& a) const {
		if (e == a.e) return w > a.w;
		return e > a.e;
	}
}A[1234567];

int maxVal, fenwick[1003];

void update(int idx, int val) {
	while (idx <= maxVal) {
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

int main() {
	int T; scanf("%d", &T);
	for(int cn = 1; cn <= T; cn++) {
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		maxVal = m;
		memset(fenwick, 0, sizeof fenwick);
		for (int i = 0; i < k; i++)
			scanf("%d%d", &A[i].e, &A[i].w);
		sort(A, A+k);
		update(A[0].w, 1);
		//update(A[0].w+1, -1);
		long long int ans = 0;
		for (int i = 1; i < k; i++) {
			ans += read(A[i].w - 1);
			update(A[i].w, 1);
			//update(A[i].w+1, -1);
		}
		printf("Test case %d: %lld\n", cn, ans);
	}
}
