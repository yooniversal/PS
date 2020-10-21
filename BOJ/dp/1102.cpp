//1102
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[1 << 16][17];
int cost[17][17];
int n, p;
string power;

int f(int state, int cnt) {
	if (cnt >= p) return 0;
	int& ret = cache[state][cnt];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < n; ++i) {
		if (state & (1 << i))
			for (int j = 0; j < n; ++j) {
				if (!(state & (1 << j)))
					ret = min(ret, f(state | (1 << j), cnt + 1) + cost[i][j]);
			}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> cost[i][j];
	cin >> power >> p;
	int state = 0;
	vi start;
	for (int i = 0; i < power.size(); ++i)
		if (power[i] == 'Y') {
			state |= (1 << i);
			start.push_back(i);
		}
	int ret = INF;
	for (int i = 0; i < start.size(); ++i)
		ret = min(ret, f(state, start.size()));

	if (p == 0) cout << 0;
	else if (ret == INF) cout << -1;
	else cout << ret;

	return 0;
}