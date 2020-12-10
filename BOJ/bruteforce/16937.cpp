//16937
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int h, w, n, ret;
bool chk[101][101], sticker[101][101];
vii a;

bool OOB(int x, int y) { return x < 0 || x >= h || y < 0 || y >= w; }

void solve(int f, int s, int used, int cnt) {
	if (used >= 2) {
		sticker[f][s] = true;
		ret = max(ret, cnt);
		return;
	}

	for (int now = f + 1; now < n; ++now) {
		if (sticker[f][s] || h*w < cnt+a[now].first*a[now].second) continue;
		int sx = h - a[now].first, sy = w - a[now].second;
		bool flag = true;
		for (int x = sx; x <= h-1; ++x) for (int y = sy; y <= w-1; ++y) {
			if (chk[x][y] || OOB(x, y)) {
				flag = false;
				x = h, y = w;
			}
		}
		if (flag) solve(f, now, used + 1, cnt + a[now].first * a[now].second);

		sx = h - a[now].second, sy = w - a[now].first;
		flag = true;
		for (int x = sx; x <= h - 1; ++x) for (int y = sy; y <= w - 1; ++y) {
			if (chk[x][y] || OOB(x, y)) {
				flag = false;
				x = h, y = w;
			}
		}
		if (flag) solve(f, now, used + 1, cnt + a[now].first * a[now].second);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> h >> w >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n - 1; ++i) {
		if (!OOB(a[i].first - 1, a[i].second - 1)) {
			for (int x = 0; x <= a[i].first - 1; ++x) for (int y = 0; y <= a[i].second - 1; ++y) chk[x][y] = true;
			solve(i, 101, 1, a[i].first * a[i].second);
			for (int x = 0; x <= a[i].first - 1; ++x) for (int y = 0; y <= a[i].second - 1; ++y) chk[x][y] = false;
		}
		if (!OOB(a[i].second - 1, a[i].first - 1)) {
			for (int x = 0; x <= a[i].second - 1; ++x) for (int y = 0; y <= a[i].first - 1; ++y) chk[x][y] = true;
			solve(i, 101, 1, a[i].first * a[i].second);
			for (int x = 0; x <= a[i].second - 1; ++x) for (int y = 0; y <= a[i].first - 1; ++y) chk[x][y] = false;
		}
	}
	cout << ret << '\n';

	return 0;
}