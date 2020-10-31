//2422
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, m, ret;
bool ban[201][201], chk[201];
vi tmp;

bool check(int next) {
	for (int i = 0; i < tmp.size(); ++i) {
		if (ban[tmp[i]][next]) return true;
	}
	return false;
}

void DFS(int cur, int cnt) {
	if (cnt == 3) {
		++ret;
		return;
	}

	for (int i = cur + 1; i <= n; ++i) {
		if (check(i)) continue;
		chk[i] = true;
		tmp.push_back(i);
		DFS(i, cnt + 1);
		tmp.pop_back();
		chk[i] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		ban[a][b] = ban[b][a] = true;
	}
	DFS(0, 0);
	cout << ret;

	return 0;
}