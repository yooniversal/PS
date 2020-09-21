//11403
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct edge {
	int s, e, v;
	bool operator<(const edge& e) const {
		return v < e.v;
	}
};

int uni[MAX];

int find(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find(uni[a]);
}

void make_union(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa < pb) uni[b] = pa;
	else uni[a] = pb;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	vector<edge> E;
	for (int i = 0; i < m; ++i) {
		int s, e, v; cin >> s >> e >> v;
		E.push_back({ s, e, v });
	}
	sort(E.begin(), E.end());

	for (int i = 0; i < n; ++i) uni[i] = i;

	int ret = 0;
	for (int i = 0; i < m; ++i) {
		int s = find(E[i].s), e = find(E[i].e);
		int c = E[i].v;

		if (s != e) {
			make_union(s, e);
			ret += c;
		}
	}
	cout << ret;

	return 0;
}