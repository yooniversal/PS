//1516
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int T[505];
int cache[505];
vi node[505];
bool chk[505];

int f(int cur) {
	if (node[cur].size() == 0) return 0;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	for (auto& next : node[cur]) {
		if (chk[next]) continue;
		chk[next] = true;
		ret = max(ret, f(next) + T[next]);
		chk[next] = false;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t; cin >> t;
		T[i] = t;
		while (1) {
			int a; cin >> a;
			if (a == -1) break;
			node[i].push_back(a);
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << f(i) + T[i] << '\n';

	return 0;
}