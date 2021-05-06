//17471
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, a[11], ret = INF;
vi adj[11];
bool team[11];

// 연결된 갯수 비교
bool search_connected(int cur) {
	vi connected;
	queue<int> q;
	bool chk[11] = { 0, };
	chk[cur] = true;
	q.push(cur);
	while (!q.empty()) {
		int c = q.front(); q.pop();
		connected.push_back(c);
		for (auto& next : adj[c]) {
			if (chk[next] || team[cur] != team[next]) continue;
			chk[next] = true;
			q.push(next);
		}
	}

	vi real;
	for (int i = 1; i <= n; ++i)
		if (team[i] == team[cur])
			real.push_back(i);

	if (connected.size() != real.size()) return false;
	sort(connected.begin(), connected.end());
	sort(real.begin(), real.end());
	for (int i = 0; i < real.size(); ++i) {
		if (connected[i] != real[i])
			return false;
	}
	return true;
}

void divide(int cur) {
	if (cur > n) {
		int sum = 0;
		for (int i = 1; i <= n; ++i) sum += team[i];
		if (sum == 0 || sum == n) return;

		bool chk[2] = { 0, };
		for (int i = 1; i <= n; ++i) {
			if (chk[team[i]]) continue;
			chk[team[i]] = true;
			if (!search_connected(i)) return; // 연결돼있지 않음
		}

		// 답 계산
		int team_sum = 0, team_sum2 = 0;
		for (int i = 1; i <= n; ++i) {
			if (team[i]) team_sum += a[i];
			else team_sum2 += a[i];
		}
		ret = min(ret, abs(team_sum - team_sum2));
		return;
	}

	for (int i = 0; i <= 1; ++i) {
		team[cur] = i;
		divide(cur + 1);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		for (int j = 0; j < x; ++j) {
			int next; cin >> next;
			adj[i].push_back(next);
		}
	}

	divide(1);
	if (ret == INF) cout << -1 << '\n';
	else cout << ret << '\n';

	return 0;
}