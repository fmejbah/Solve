/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 1266 - Points in Rectangle.cpp
 * Date: 25 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1003;

int fenwick[N][N], mat[N][N];

void update(int x, int y, int val) {
	while (x < N) {
		int y1 = y;
		while (y1 < N) {
			fenwick[x][y1] += val;
			y1 += y1 & -y1;
		}
		x += x & -x;
	}
}

int read(int x, int y) {
	int sum = 0;
	while (x > 0) {
		int y1 = y;
		while (y1 > 0) {
			sum += fenwick[x][y1];
			y1 -= y1 & -y1;
		}
		x -= x & -x;
	}
	return sum;
}

int main() {
	int T; scanf("%d", &T);
	for (int cn = 1; cn <= T; cn++ ) {
		int q; scanf("%d", &q);
		memset(fenwick, 0, sizeof fenwick);
		memset(mat, 0, sizeof mat);
		printf("Case %d:\n", cn);
		while (q--) {
			int t; scanf("%d", &t);
			if (t == 0) {
				int x, y; scanf("%d%d", &x, &y);
				if (mat[x][y] == 0) {
					update(x + 1, y + 1, 1);
					mat[x][y] = 1;
				}
			} else {
				int x1, y1, x2, y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				x2++, y2++;
				int r = read(x2, y2) - read(x1, y2) - read(x2, y1) + read(x1, y1);
				printf("%d\n", r);
			}
		}
	}
}
