//19584
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct L {
	int y, w, start;
	L(int a, int b, int c) : y(a), w(b), start(c) {}

	bool operator<(L& a) {
		if (y == a.y) return start > a.start;
		return y > a.y;
	}
};

int n, m;
int Y[200001];
vector<L> lines;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x, y; cin >> x >> y;
		Y[i] = y;
	}

	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		lines.emplace_back(L(max(Y[u], Y[v]), w, 1));
		lines.emplace_back(L(min(Y[u], Y[v]), w, 0));
	}
	sort(lines.begin(), lines.end());

	ll ret = 0, cur = 0;
	for (auto& l : lines) {
		if (l.start) cur += l.w;
		else cur -= l.w;
		ret = max(ret, cur);
	}

	cout << ret << '\n';

	return 0;
}