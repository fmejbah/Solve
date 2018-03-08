/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 4682 - XOR Sum.cpp
 * Date: 29 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

struct node {
	node *next[3];
	node() {
		for (int i = 0; i < 3; i++)
			next[i] = NULL;
	}
}*root;

string bitsString(int n) {
	string s = "";
	while (n) {
		s += (n&1) + '0';
		n >>= 1;
	}
	reverse(s.begin(), s.end());
	while (s.length() < 32)
		s = "0" + s;
	return s;
}

void insert(int n) {
	string s = bitsString(n);
	node *curr = root;
	for (int i = 0; i < s.length(); i++) {
		int id = s[i] - '0';
		if (curr->next[id] == NULL)
			curr->next[id] = new node();
		curr = curr->next[id];
	}
}

int query(int n) {
	string s = bitsString(n);
	node *curr = root;
	int ret = 0;
	for (int i = 0, l = 31; i < s.length(); i++, l--) {
		if (s[i] == '0' && curr->next[1] != NULL) {
			ret += (1 << l);
			curr = curr->next[1];
		} else if (s[i] == '1' && curr->next[0] != NULL) {
			ret += (1 << l);
			curr = curr->next[0];
		} else if (curr->next[0] != NULL) {
			curr = curr->next[0];
		} else {
			curr = curr->next[1];
		}
	}
	return ret;
}

void clearMemory(node *curr) {
	for (int i = 0; i < 3; i++)
		if (curr->next[i] != NULL)
			clearMemory(curr->next[i]);
	delete(curr);
}


int main() {
	int t; scanf("%d", &t);
	while (t--) {
		root = new node();
		int n; scanf("%d", &n);
		int pre = 0, ans = 0;
		insert(pre);
		while (n--) {
			int x; scanf("%d", &x);
			pre ^= x;
			insert(pre);
			ans = max(ans, query(pre));
		}
		printf("%d\n", ans);
		clearMemory(root);
	}
}
