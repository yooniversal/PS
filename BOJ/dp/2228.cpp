//2228
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, m;
int cache[101][52][2];
vi arr;

int f(int cur, int turn, int on) {
	if (cur == n-1) {
		if (turn == m) return 0;
		return -INF;
	}
	int& ret = cache[cur][turn][on];
	if (ret != -1) return ret;
	ret = -INF;
	if (on == 1) {
		ret = max(ret, f(cur + 1, turn, 1) + arr[cur + 1]);
		ret = max(ret, f(cur + 1, turn, 0));
	}
	else {
		ret = max(ret, f(cur + 1, turn, 0));
		ret = max(ret, f(cur + 1, turn + 1, 1) + arr[cur + 1]);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	int ret = -INF;
	ret = max(ret, f(0, 1, 1)+arr[0]);
	ret = max(ret, f(0, 0, 0));
	cout << ret;

	return 0;
}