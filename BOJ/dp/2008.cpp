//2008
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

ll cache[101][501];
int n, m, a, b, X, Y;
vi bridge[101];

//from번 세로선에 cur번 이상의 가로선이 있는지
//있다면 번호를, 없다면 INF을 반환
int canMove(int from, int cur) {
	auto it = lower_bound(bridge[from].begin(), bridge[from].end(), cur);
	if (it == bridge[from].end()) return INF;
	return *it;
}

ll f(int from, int cnt) {
	if (from < 1 || from > n) return INF;
	ll& ret = cache[from][cnt];
	if (ret != -1) return ret;
	ret = INF;
	ret = min(ret, min(f(from - 1, cnt), f(from + 1, cnt)) + Y);
	int L = canMove(from - 1, cnt + 1), R = canMove(from, cnt + 1);
	if (L != INF || R != INF) {
		if (L < R) ret = min(ret, min(f(from - 1, L), f(from, L) + X));
		else ret = min(ret, min(f(from + 1, R), f(from, R) + X));
	}
	else if (from == b) ret = 0;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> a >> b >> X >> Y;
	for (int i = 1; i <= m; ++i) {
		int p; cin >> p;
		bridge[p].push_back(i);
	}
	cout << f(a, 0) << '\n';

	return 0;
}