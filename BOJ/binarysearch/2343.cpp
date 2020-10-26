//2343
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi a;
int N, M;

ll binary_search(ll l, ll r) {
	while (l <= r) {
		ll sum = 0, m = (l + r) / 2, cnt = 0;
		for (int i = 0; i < N; ++i) {
			if (sum + a[i] > m) {
				++cnt;
				sum = 0;
			}
			sum += a[i];
		}
		if (sum != 0) ++cnt;
		if (cnt > M) l = m+1;
		else r = m-1;
	}
	return l;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	a.resize(N);
	int maxx = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}

	cout << binary_search(maxx, 1000000001);

	return 0;
}