//8982
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int water[40001]; //열마다 차있는 물의 높이 (기본값)
int remain[40001]; //열마다 차있는 실제 물의 높이

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	int px = -1, bound = 0; //이전 x, 끝 x
	for (int i = 1; i <= n; ++i) {
		int x, y; cin >> x >> y;
		--x;	
		if (i <= 2 || i % 2 == 0) continue;
		for (int i = px + 1; i <= x; ++i) water[i] = y;
		px = x;
		bound = max(bound, x);
	}

	for (int i = 0; i <= bound; ++i) remain[i] = water[i];

	int k; cin >> k;
	int dx[] = { -1,1 };
	for (int i = 0; i < k; ++i) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		remain[a] = min(remain[a], water[a] - b);
		for (int j = 0; j < 2; ++j) {
			int nx = a + dx[j];
			int h = b; //없애는 기준
			while (0 <= nx && nx <= bound) {
				if (water[nx] - h < 0) h = water[nx];
				remain[nx] = min(remain[nx], water[nx] - h);
				nx += dx[j];
			}
		}
	}

	int ret = 0;
	for (int i = 0; i <= bound; ++i) ret += remain[i];
	cout << ret << '\n';

	return 0;
}