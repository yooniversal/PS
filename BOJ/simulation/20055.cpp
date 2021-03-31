//20055
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, k, a[201];
bool robot[201];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= 2 * n; ++i) cin >> a[i];
	int cnt = 0, kcnt = 0;
	while (1) {
		++cnt;
		// 벨트 회전
		int tmp = a[2 * n], rtmp = robot[2 * n];
		for (int i = 2 * n - 1; i >= 1; --i) {
			a[i + 1] = a[i], robot[i + 1] = robot[i];
		}
		robot[n] = false;
		a[1] = tmp, robot[1] = rtmp;

		// 로봇 이동
		bool r1 = robot[1];
		for (int i = 2 * n; i >= 2; --i) {
			if (!robot[i]) continue;
			int next = i == 2 * n ? 1 : i + 1;
			if (robot[next] || a[next] == 0) continue;
			robot[next] = true;
			robot[i] = false;
			--a[next];
			if (a[next] == 0) ++kcnt;
		}
		robot[n] = false;
		if (r1 && a[2] && !robot[2]) {
			robot[2] = r1;
			robot[1] = false;
			--a[2];
			if (a[2] == 0) ++kcnt;
		}

		// 올라가는 위치에 로봇이 없다면 하나 올린다
		if (!robot[1] && a[1]) {
			--a[1];
			robot[1] = true;

			if (a[1] == 0) ++kcnt;
		}
		
		// 종료 조건
		if (kcnt >= k) break;
	}
	cout << cnt << '\n';

	return 0;
}