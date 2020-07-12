//1991

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

pair<char, int> arr[1000001];

int getidx(char c) {

	int idx = 1;
	while (arr[idx].first != c) idx++;
	return idx;
}

void preorder(int root) {
	if (arr[root].first != '.' && arr[root].first != ' ')
		cout << arr[root].first;
	else return;
	preorder(root * 2);
	preorder(root * 2 + 1);
}

void inorder(int root) {
	if (!(arr[root].first != '.' && arr[root].first != ' ')) return;
	inorder(root * 2);
	if (arr[root].first != '.' && arr[root].first != ' ')
		cout << arr[root].first;
	else return;
	inorder(root * 2 + 1);
}

void postorder(int root) {
	if (!(arr[root].first != '.' && arr[root].first != ' ')) return;
	postorder(root * 2);
	postorder(root * 2 + 1);
	if (arr[root].first != '.' && arr[root].first != ' ')
		cout << arr[root].first;
	else return;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	//input
	for (int i = 0; i < n; i++) {
		char p, l, r;
		cin >> p >> l >> r;
		if (i == 0) arr[1] = { p, 1 };
		arr[getidx(p) * 2] = { l, getidx(p) * 2 };
		arr[getidx(p) * 2 + 1] = {r, getidx(p) * 2 + 1};
	}

	//process
	preorder(1);
	cout << '\n';
	inorder(1);
	cout << '\n';
	postorder(1);

	return 0;
}