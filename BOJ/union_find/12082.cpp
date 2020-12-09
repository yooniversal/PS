//12082
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int uni[201];

int find(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find(uni[a]);
}

void makeUnion(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa < pb) uni[pb] = pa;
	else uni[pa] = pb;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	for(int T = 1; T<=t; ++T) {
		for (int i = 0; i <= 200; ++i) uni[i] = i;
		int n, cnt = 0; cin >> n;
		map<string, int> m;
		vii arr;
		for (int i = 0; i < n; ++i) {
			string a, b; cin >> a >> b;
			if (m[a] == 0) m[a] = ++cnt;
			if (m[b] == 0) m[b] = ++cnt;
			arr.push_back({ m[a], m[b] });
		}
		for (auto i : arr) {
			makeUnion(i.first, i.second + cnt);
			makeUnion(i.second, i.first + cnt);
		}
		bool flag = true;
		for(int i=1; i<=cnt; ++i)
			if (find(i) == find(i + cnt)) {
				flag = false;
				break;
			}
		if (flag) cout << "Case #" << T << ": Yes\n";
		else cout << "Case #" << T << ": No\n";
	}

	return 0;
}