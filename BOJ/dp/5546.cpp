//5546
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

int n, k;
int fix[101];
int cache[101][4][3];

int f(int day, int prev, int cnt) {
	if (day == n+1) {
		if (cnt == 3) return -INF;
		return 1;
	}
	int& ret = cache[day][prev][cnt];
	if (ret != -1) return ret;
	ret = 0;
	if (fix[day] != -1) {
		if (fix[day] == prev) {
			if (cnt < 2) ret += f(day + 1, fix[day], cnt + 1) % 10000;
		}
		else ret += f(day + 1, fix[day], 1) % 10000;
	}
	else {
		for (int i = 1; i <= 3; ++i) {
			if (prev == i) {
				if (cnt < 2) ret += f(day + 1, prev, cnt + 1) % 10000;
			}
			else
				ret += f(day + 1, i, 1) % 10000;
		}
	}
	ret %= 10000;
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	memset(fix, -1, sizeof(fix));
	cin >> n >> k;
	while (k--) {
		int day, kind; cin >> day >> kind;
		fix[day] = kind;
	}
	int ret = 0;
	if (fix[1] == -1) {
		for (int i = 1; i <= 3; ++i) {
			ret += f(2, i, 1) % 10000;
			ret %= 10000;
		}
	}
	else {
		ret = f(2, fix[1], 1) % 10000;
	}
	cout << ret;

	return 0;
}