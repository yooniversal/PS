//2109
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

int n;
vii a;

bool cmp(const ii& a, const ii& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int END = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int p, d; cin >> p >> d;
		a.push_back({ d,p });
		END = max(END, d);
	}
	sort(a.begin(), a.end(), cmp);

	int idx = 0;
	ll ret = 0;
	priority_queue<int> pq;
	for (int day = END; day >= 1; --day) {
		while (idx < n && a[idx].first == day)
			pq.push(a[idx++].second);
		if (!pq.empty()) {
			ret += pq.top(); pq.pop();
		}
 	}
	cout << ret << '\n';

	return 0;
}