/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * 10226 - Hardwood Species.cpp
 * Date: 29 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

struct node {
	int endMark;
	node *next[130];
	node() {
		endMark = 0;
		for (int i = 0; i < 130; i++)
			next[i] = NULL;
	}
}*root;

void insert(string s) {
	node *curr = root;
	for (int i = 0; i < s.length(); i++) {
		int id = s[i];
		if (curr->next[id] == NULL)
			curr->next[id] = new node();
		curr = curr->next[id];
	}
	curr->endMark++;
}

void clearMemory(node *curr) {
	for (int i = 0; i < 130; i++)
		if (curr->next[i] != NULL)
			clearMemory(curr->next[i]);
	delete(curr);
}

void print(node *curr, string s, int n) {
	for (int i = 0; i < 130; i++)
		if (curr->next[i] != NULL) {
			char c = i;
			print(curr->next[i], s + c, n);
		}
	if (curr->endMark) {
		cout << s;
		printf(" %.4f\n", (100.0 * curr->endMark) / n);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t; scanf("%d", &t);
	string s;
	cin.ignore();
	cin.ignore();
	while (t--) {
		//cin.ignore();
		root = new node();
		int n = 0;
		while (getline(cin, s)) {
			if(s == "") break;
			insert(s);
			n++;
		}
		print(root, "", n);
		clearMemory(root);
		if (t) puts("");
	}
}
