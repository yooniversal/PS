//9019

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

struct tr {
	bool c;
	int prev;
	char a;

	tr() : c(false), prev(-1), a(' ')
	{
	}

	tr(bool nf, int val, char ans) : c(nf), prev(val), a(ans)
	{
	}
};

int Y;
tr chk[10001];
stack<char> result;	//결과값 담기

void prt(int n) {
	result.push(chk[n].a);
	if(chk[n].prev != -1)
		prt(chk[n].prev);
}

void fin() {
	if (chk[Y].prev != -1)
		prt(Y);
	while (!result.empty()) {
		if (result.top() != ' ')
			cout << result.top();
		result.pop();
	}
}

void bfs(int start) {
	queue<int> que;
	que.push(start);

	while (!que.empty()) {
		int cur = que.front(); que.pop();
		chk[cur].c = true;

		//D
		if (chk[(2 * cur) % 10000].c == false) {
			chk[(2 * cur) % 10000] = tr(true, cur, 'D');
			que.push((2 * cur) % 10000);

			if (chk[Y].c == true) break;
		}
		//S
		int tmp = cur == 0 ? 9999 : cur-1;
		if (!chk[tmp].c) {
			chk[tmp] = tr(true, cur, 'S');
			que.push(tmp);

			if (chk[Y].c == true) break;
		}
		//L
		int Lcur = (cur % 1000) * 10 + (cur / 1000);
		if (!chk[Lcur].c) {
			chk[Lcur] = tr(true, cur, 'L');
			que.push(Lcur);

			if (chk[Y].c == true) break;
		}
		//R
		int Rcur = (cur % 10) * 1000 + (cur / 10);
		if (!chk[Rcur].c) {
			chk[Rcur] = tr(true, cur, 'R');
			que.push(Rcur);

			if (chk[Y].c == true) break;
		}
	}

	fin();
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int X, t;
	cin >> t;
	while (t--) {
		cin >> X >> Y;
		bfs(X);
		cout << '\n';

		for(int i=0; i<10000; i++) chk[i] = tr(false, -1, ' ');
	}

	return 0;
}