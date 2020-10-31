//2568
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

int convert[500001];
bool selected[500001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vi a, target;
	int n; cin >> n;

	vii line(n);
	for (int i = 0; i < n; ++i) {
		int start, end; cin >> start >> end;
		line[i] = { start, end };
		convert[end] = start;
	}
	sort(line.begin(), line.end());

	a.resize(n);
	for (int i = 0; i < n; ++i)
		a[i] = line[i].second;

	stack<ii> tmp; //ÀÎµ¦½º, °ª
	int cnt = 0;
	target.push_back(-INF);
	for (int i = 0; i < n; ++i) {
		if (target[cnt] < a[i]) {
			tmp.push({ ++cnt, a[i] });
			target.push_back(a[i]);
		}
		else {
			auto it = lower_bound(target.begin(), target.end(), a[i]);
			int idx = it - target.begin();
			tmp.push({ idx, a[i] });
			*it = a[i];
		}
	}

	cout << n - (target.size() - 1) << '\n';
	vi order;
	while (cnt) {
		if (tmp.top().first == cnt) {
			order.push_back(tmp.top().second);
			--cnt;
		}
		tmp.pop();
	}

	for (int i = 0; i < order.size(); ++i) selected[convert[order[i]]] = true;
	for (int i = 0; i < n; ++i)
		if (!selected[line[i].first])
			cout << line[i].first << '\n';

	return 0;
}
