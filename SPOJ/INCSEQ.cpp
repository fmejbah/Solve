/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * INCSEQ.cpp
 * Date: 25 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;

int fenwick[51][N];

void update(int k, int idx, int val) {
	while (idx < N) {
		fenwick[k][idx] += val;
		if (fenwick[k][idx] >= 5000000)
			fenwick[k][idx] -= 5000000;
		idx += idx & -idx;
	}
}

int read(int k, int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += fenwick[k][idx];
		if (sum >= 5000000) sum -= 5000000;
		idx -= idx & -idx;
	}
	return sum;
}

int main() {
	//memset(fenwick, 0, sizeof fenwick);
	int n, k, x; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		x++;
		update(1, x, 1);
		for (int j = 2; j <= k; j++)
			update(j, x, read(j - 1, x - 1));
	}
	printf("%d\n", read(k, N - 1));
}
