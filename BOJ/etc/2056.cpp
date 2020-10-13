//2056
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[10001];
int TIME[10001];
vi node[10001];

int f(int cur) {
	if (node[cur].size() == 0) return TIME[cur];
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	for (auto& next : node[cur]) {
		ret = max(ret, f(next));
	}
	ret += TIME[cur];
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	
	int n; cin >> n;
	for(int i=1; i<=n; ++i){
		int t, m; cin >> t >> m;
		TIME[i] = t;
		while (m--) {
			int adj; cin >> adj;
			node[i].push_back(adj);
		}
	}
	
	int ret = 0;
	for (int i = 1; i <= n; ++i)
		ret = max(ret, f(i));
	cout << ret;

	return 0;
}