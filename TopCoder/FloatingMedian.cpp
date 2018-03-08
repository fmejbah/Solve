/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * FloatingMedian.cpp
 * Date: 24 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

const int mod = 65536;

int fenwick[mod + 2];

void update(int idx, int val) {
	while (idx <= mod) {
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

int median(int m) {
	int low = 1, high = mod, mid, r = -1;
	//cout << "read(mid):";
	while (low <= high) {
		mid = (low + high) / 2;
		//cout << ' ' << read(mid);
		if (read(mid) >= m) {
			high = mid - 1;
			r = mid;
		} else {
			low = mid + 1;
		}
	}
	//puts("");
	return r;
}

class FloatingMedian {
	public:
		long sumOfMedians(int seed, int mul, int add, int N, int K) {
			memset(fenwick, 0, sizeof fenwick);
			int temperatures[N];
			temperatures[0] = seed;
			update(temperatures[0] + 1, 1);
			long long M = mul;
			for (int i = 1; i < N; i++ ) {
				temperatures[i] = (temperatures[i-1] * M + add) % mod;
				if (i < K) update(temperatures[i] + 1, 1);
			}
			//for (int i = 0; i < N; i++) cout << temperatures[i] << ' '; puts("");
			for (int i = 0; i < N; i++)
				temperatures[i]++;
			int k = (K + 1) / 2;
			long r = median(k) - 1;
			//cout << r << endl;
			for (int i = K, j = 0; i < N; i++, j++) {
				update(temperatures[j], -1);
				update(temperatures[i], 1);
				r += median(k) - 1;
			//cout << median(k) << endl;
			}
			return r;
		}
};

int main()
{
	FloatingMedian a;
	cout << a.sumOfMedians(3, 1, 1, 10, 3) << endl;
	cout << a.sumOfMedians(10, 0, 13, 5, 2) << endl;
	cout << a.sumOfMedians(4123, 2341, 1231, 7, 3) << endl;
	cout << a.sumOfMedians(47, 5621, 1, 125000, 1700) << endl;
	cout << a.sumOfMedians(32321, 46543, 32552, 17, 17) << endl;
}
