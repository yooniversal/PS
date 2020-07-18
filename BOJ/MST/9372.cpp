//9372

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
#include <map>
using namespace std;

int uni[1001];

//부모 노드 반환
int find_parent(int a) {
	if (uni[a] == a) {
		return a;
	}
	return uni[a] = find_parent(uni[a]);
}

//같은 집합으로 만들어주기
void make_union(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);
	if (pa != pb) {
		if (pa < pb) {
			uni[pb] = pa;
		}
		else {
			uni[pa] = pb;
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int ans = 0;
		queue<pair<int, int>> route;

		//union-find 초기화
		for (int i = 0; i <= n; i++)
			uni[i] = i;

		//input
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			route.push({ a, b });
		}
		
		while (!route.empty()) {
			int s = route.front().first;
			int e = route.front().second;
			route.pop();

			if (ans == n - 1) break;	//종료 조건
			if (find_parent(s) == e || find_parent(e) == s) continue;

			make_union(s, e);
			ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}