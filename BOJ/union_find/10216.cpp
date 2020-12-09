//10216
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

struct P {
	int x, y, r, n;
};

int uni[3001];

int find(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find(uni[a]);
}

void makeUnion(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa < pb) uni[pb] = pa;
	else uni[pa] = pb;
}

void solve(P& a, P& b) {
	int xy = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	int rr = (a.r + b.r) * (a.r + b.r);
	if (xy <= rr) makeUnion(a.n, b.n);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	for (int T = 1; T <= t; ++T) {
		for (int i = 0; i < 3001; ++i) uni[i] = i;
		int n; cin >> n;
		vector<P> a;
		for (int i = 1; i <= n; ++i) {
			int x, y, r; cin >> x >> y >> r;
			a.push_back({ x,y,r,i });
		}
		for (int i = 0; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j)
				solve(a[i], a[j]);
		int ret = 0;
		for (int i = 1; i <= n; ++i)
			if (find(i) == i) ++ret;
		cout << ret << '\n';
	}

	return 0;
}