//17610
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1000000007;

bool ret[2600001];
int n;
vi a;

void DFS(int i, int cur) {
	if (i == n) {
		if (cur > 0) ret[cur] = true;
		return;
	}
	DFS(i + 1, cur + a[i]);
	DFS(i + 1, cur - a[i]);
	DFS(i + 1, cur);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	a.resize(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	DFS(0, 0);

	int ans = 0;
	for (int i = 1; i <= sum; ++i)
		if (!ret[i]) ++ans;
	cout << ans << '\n';
	
	return 0;
}