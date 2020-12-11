//2535
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 5005, INF = 1000000001, MOD = 1234567;

struct P {
	int c, r, s;
	bool operator<(P& a) {
		return s > a.s;
	}
};

int country[101];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<P> arr;
	for (int i = 0; i < n; ++i) {
		int c, r, s; cin >> c >> r >> s;
		arr.push_back({ c,r,s });
	}
	sort(arr.begin(), arr.end());

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (country[arr[i].c]++ >= 2) continue;
		cout << arr[i].c << ' ' << arr[i].r << '\n';
		if (++cnt == 3) break;
	}

	return 0;
}