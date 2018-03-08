/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * FairWorkload.cpp
 * Date: 29 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

class FairWorkload {
	public:
		int getMostWork(vector<int> folders, int workers) {
			int N = (int) folders.size();
			int low = folders[0];
			for (int i = 1; i < N; i++)
				low = max(low, folders[i]);
			for (int i = 1; i < N; i++)
				folders[i] += folders[i - 1];
			int high = folders[N - 1];
			while (low < high) {
				int mid = low + (high - low) / 2;
				int pre = 0, n = 0;
				for (int i = 0; i < N; ) {
					while (i < N && folders[i] - pre <= mid) i++;
					if (folders[i - 1] - pre <= mid) {
						pre = folders[i - 1];
						n++;
					}
				}
				if (n <= workers) high = mid;
				else low = mid + 1;
			}
			return low;
		}
};

int main() {
	FairWorkload a;
	int A0[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	vector<int> v0(A0, A0 + 9);
	cout << a.getMostWork(v0, 3) << endl;
	int A1[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	vector<int> v1(A1, A1 + 9);
	cout << a.getMostWork(v1, 5) << endl;
	int A2[] = {568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782}; 
	vector<int> v2(A2, A2 + 15);
	cout << a.getMostWork(v2, 4) << endl;
	int A3[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000 };
	vector<int> v3(A3, A3 + 15);
	cout << a.getMostWork(v3, 2) << endl;
	int A4[] = { 50, 50, 50, 50, 50, 50, 50 };
	vector<int> v4(A4, A4 + 7);
	cout << a.getMostWork(v4, 2) << endl;
	int A5[] = {1,1,1,1,100};
	vector<int> v5(A5, A5 + 5);
	cout << a.getMostWork(v5, 5) << endl;
	int A6[] = { 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 };
	vector<int> v6(A6, A6 + 10);
	cout << a.getMostWork(v6, 6) << endl;
}
