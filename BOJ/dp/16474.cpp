//16474
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 605
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int st[2005], ed[2005];
int n, m, x;
vi E[2005];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		st[x] = i;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> x;
		ed[x] = i;
	}
	int k; cin >> k;
	for(int i=0; i<k; ++i) {
		int u, v; cin >> u >> v;
		E[st[u]].push_back(ed[v]);
	}

	vi target;
	for (int i = 1; i <= n; ++i) {
		sort(E[i].rbegin(), E[i].rend());
		for (int& next : E[i]) {
			if (target.empty() || target.back() < next)
				target.push_back(next);
			else {
				auto it = lower_bound(target.begin(), target.end(), next);
				*it = next;
			}
		}
	}
	cout << k - target.size();

	return 0;
}