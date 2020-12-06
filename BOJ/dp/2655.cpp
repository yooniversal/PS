//2655
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1000000007;

struct P {
	int s, h, w;
};

int cache[101], from[101], n;
bool chk[101];
vector<P> wall;

int f(int cur) {
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < n; ++i) {
		if (wall[i].s >= wall[cur].s || wall[i].w >= wall[cur].w) continue;
		if (chk[i]) continue;
		chk[i] = true;
		if (ret < f(i) + wall[i].h) {
			ret = f(i) + wall[i].h;
			from[cur] = i;
		}
		chk[i] = false;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	memset(from, -1, sizeof(from));
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int s, h, w; cin >> s >> h >> w;
		wall.push_back({ s,h,w });
	}
	
	int ret = 0, start;
	for (int i = 0; i < n; ++i) {
		chk[i] = true;
		if (ret < f(i) + wall[i].h) {
			ret = f(i) + wall[i].h;
			start = i;
		}
		chk[i] = false;
	}
	
	vi route;
	for (int i = start; i != -1; i = from[i]) route.push_back(i + 1);
	cout << route.size() << '\n';
	for (int i = route.size() - 1; i >= 0; --i) cout << route[i] << '\n';

	return 0;
}