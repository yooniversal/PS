//14391
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 9901;

int n, m, ret;
int a[16];

void solve(int chk, int tmp, int cur) {
	if (chk == (1<<(n*m))-1) {
		ret = max(ret, tmp);
		return;
	}

	if (chk & (1 << cur)) {
		solve(chk, tmp, cur + 1);
		return;
	}

	int status = chk, add = 0;
	//가로 확장
	for (int i = cur; i%m != 0 || i==cur; ++i) {
		if (status & (1<<i)) break;
		status |= (1<<i);
		add = add * 10 + a[i];
		solve(status, tmp + add, i + 1);
	}

	//세로 확장
	status = chk | (1<<cur), add = a[cur];
	for (int i = cur + m; i <= n*m-1; i += m) {
		if (status & (1<<i)) break;
		add = add * 10 + a[i];
		status |= (1 << i);
		solve(status, tmp + add, cur + 1);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			a[j + i * m] = s[j] - '0';
		}
	}

	solve(0, 0, 0);

	cout << ret << '\n';

	return 0;
}