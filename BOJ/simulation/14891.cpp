//14891
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { -1, 1 };
vector<string> wheel;
bool chk[4];

//dir 1:시계, -1:반시계
string rotate(string& s, int dir) {
	string ret;
	if (dir == -1)
		ret = s.substr(1, 8) + s[0];
	else
		ret = s[7] + s.substr(0, 7);
	return ret;
}

void solve(int n, int dir) {
	memset(chk, 0, sizeof(chk));
	queue<ii> q;
	q.push({ n, dir });
	chk[n] = true;
	vii v;
	while (!q.empty()) {
		int n = q.front().first, dir = q.front().second; q.pop();
		v.push_back({ n, dir });
		int nextDir;
		if (dir == -1) nextDir = 1;
		else nextDir = -1;
		for (int i = 0; i < 2; ++i) {
			int nx = n + dx[i];
			if (nx < 0 || nx >= 4) continue;
			if (chk[nx]) continue;
			chk[nx] = true;
			if (i == 0 && wheel[n][6] == wheel[nx][2]) continue;
			if (i == 1 && wheel[n][2] == wheel[nx][6]) continue;
			q.push({ nx, nextDir });
		}
	}
	
	for (int i = 0; i < v.size(); ++i) {
		wheel[v[i].first] = rotate(wheel[v[i].first], v[i].second);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	wheel.resize(4);
	for (int i = 0; i < 4; ++i) cin >> wheel[i];
	int m; cin >> m;
	while (m--) {
		int n, dir; cin >> n >> dir;
		solve(--n, dir);
	}

	int ret = 0;
	ret += wheel[0][0] == '0' ? 0 : 1;
	ret += wheel[1][0] == '0' ? 0 : 2;
	ret += wheel[2][0] == '0' ? 0 : 4;
	ret += wheel[3][0] == '0' ? 0 : 8;
	cout << ret;

	return 0;
}