//1976

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

int n, m;
int uni[205];

int find_parent(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find_parent(uni[a]);
}

void make_union(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);
	if (pa != pb) {
		if (pa < pb) uni[pb] = pa;
		else uni[pa] = pb;
	}
}

bool check_union(int a, int b) {
	if (find_parent(a) == find_parent(b)) return true;
	else return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	//부모 노드를 가리키도록 초기화
	for (int i = 0; i <= n; i++)
		uni[i] = i;
	
	//노드 연결
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int connect; cin >> connect;
			if(connect) make_union(i, j);
		}
	}

	vector<int> chk;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		chk.push_back(tmp);
	}
	int ans = 1;
	for (int i = 1; i < m; i++) {
		if (check_union(chk[i - 1], chk[i])) continue;
		else {
			ans = 0;
			break;
		}
	}

	if (ans) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}