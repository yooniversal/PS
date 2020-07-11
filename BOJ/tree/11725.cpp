//11725

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

int node[100001];
stack<pair<int, int>> t1, t2;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, fir, sec;

	node[1] = -1; //root node

	cin >> num;
	for (int i = 0; i < num - 1; i++) {
		cin >> fir >> sec;
		if (node[fir] == 0 && node[sec] == 0) t1.push({ fir, sec });
		else {
			if (node[fir] == 0) node[fir] = sec;
			else node[sec] = fir;
		}
	}

	while (!(t1.empty() && t2.empty())) {
		while (!t1.empty()) {
			int x = t1.top().first, y = t1.top().second;
			t1.pop();
			if (node[x] == 0 && node[y] == 0) t2.push({ x, y });
			else {
				if (node[x] == 0) node[x] = y;
				else node[y] = x;
			}
		}
		while (!t2.empty()) {
			int x = t2.top().first, y = t2.top().second;
			t2.pop();
			if (node[x] == 0 && node[y] == 0) t1.push({ x, y });
			else {
				if (node[x] == 0) node[x] = y;
				else node[y] = x;
			}
		}
	}


	for (int i = 2; i <= num; i++) cout << node[i] << '\n';

	return 0;
}