/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * SUBXOR.cpp
 * Date: 29 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

struct node {
	int l, r;
	node *left, *right;
	node() {
		l = r = 0;
		left = right = NULL;
	}
}*root;

string bitsString(int n) {
	string s = "";
	while (n) {
		s += (n&1) + '0';
		n >>= 1;
	}
	while (s.length() < 23)
		s += '0';
	reverse(s.begin(), s.end());
	return s;
}

void insert(int n, int a) {
	string s = bitsString(n);
	node *curr = root;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			if (curr->left == NULL)
				curr->left = new node();
			curr = curr->left;
			curr->l += a;
		} else {
			if (curr->right == NULL)
				curr->right = new node();
			curr = curr->right;
			curr->r += a;
		}
	}
}

string s1, s2;

int query(node *curr, int i) {
	if (i >= 23) return 0;
	int r = 0;
	if (s2[i] == '1' && s1[i] == '0' && curr->left != NULL)
		r += curr->l;
	if (s2[i] == '1' && s1[i] == '1' && curr->right != NULL)
		r += curr->r;
	if (s2[i] == '1' && s1[i] == '1' && curr->left != NULL)
		r += query(curr->left, i + 1);
	if (s2[i] == '0' && s1[i] == '1' && curr->right != NULL)
		r += query(curr->right, i + 1);
	if (s2[i] == '0' && s1[i] == '0' && curr->left != NULL)
		r += query(curr->left, i + 1);
	return r;
}

void clearMemory(node *curr) {
	if (curr->left != NULL)
		clearMemory(curr->left);
	if (curr->right != NULL)
		clearMemory(curr->right);
	delete(curr);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		int pre = 0;
		long long int ans = 0;
		root = new node();
		insert(0, 0);
		s2 = bitsString(k);
		while (n--) {
			int x; scanf("%d", &x);
			pre ^= x;
			insert(pre, 1);
			s1 = bitsString(pre);
			ans += query(root, 0);
		}
		clearMemory(root);
		printf("%lld\n", ans);
	}
}
