/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * MATSUM.cpp
 * Date: 25 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1025;

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
			y1 -= y1 & - y1;
		}
		x -= x & -x;
	}
	return sum;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		memset(fenwick, 0, sizeof fenwick);
		memset(mat, 0, sizeof mat);
		while (1) {
			char s[4]; scanf("%s", s);
			if (s[1] == 'E') {
				int x, y, v; scanf("%d%d%d", &x, &y, &v);
				if (mat[x][y] != 0) {
					update(x + 1, y + 1, -mat[x][y]);
					mat[x][y] = 0;
				}
				update(x + 1, y + 1, v);
				mat[x][y] = v;
			} else if (s[1] == 'U') {
				int x1, y1, x2, y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			  x2++, y2++;
				int r = read(x2, y2) - read(x1, y2) - read(x2, y1) + read(x1, y1);
				printf("%d\n", r);
			} else {
				break;
			}
		}
		printf("\n");
	}
}
