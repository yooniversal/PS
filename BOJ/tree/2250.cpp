//2250
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10001, INF = 1000000001, MOD = 9901;

int n, cnt, LEVEL;
int node[MAX], width[MAX], parent[MAX];
vi level[MAX];
ii tree[MAX];

void DFS(int cur, int cur_level) {
	LEVEL = max(LEVEL, cur_level);
	level[cur_level].emplace_back(cur);

	if (tree[cur].first != -1 && tree[cur].first != 0)
		DFS(tree[cur].first, cur_level + 1);

	node[cur] = ++cnt;

	if (tree[cur].second != -1 && tree[cur].second != 0)
		DFS(tree[cur].second, cur_level + 1);
}

int searchRoot(int cur) {
	if (parent[cur] == 0) return cur;
	return searchRoot(parent[cur]);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int p, l, r; cin >> p >> l >> r;
		tree[p].first = l;
		tree[p].second = r;
		if (l != -1) parent[l] = p;
		if (r != -1) parent[r] = p;
	}

	int root = -1;
	for(int i=1; i<=n; ++i)
		if (tree[i].first - 1 && tree[i].second == -1) {
			root = searchRoot(i);
			break;
		}

	DFS(root, 1);

	for (int i = 1; i <= LEVEL; ++i)
		width[i] = node[level[i].back()] - node[level[i].front()] + 1;
	
	ii ret = { 1, 0 };
	for (int i = 1; i <= LEVEL; ++i) {
		if (ret.second < width[i]) {
			ret.first = i;
			ret.second = width[i];
		}
	}

	cout << ret.first << ' ' << ret.second << '\n';

	return 0;
}