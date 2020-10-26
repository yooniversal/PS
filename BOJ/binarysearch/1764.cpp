//1764
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

vector<string> a;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n + m; ++i) {
		string s; cin >> s;
		a.push_back(s);
	}
	sort(a.begin(), a.end());

	vector<string> ret;
	for (int i = 0; i < a.size()-1; ++i) {
		if (a[i] == a[i + 1]) {
			ret.push_back(a[i]);
			++i;
		}
	}

	cout << ret.size() << '\n';
	for (auto s : ret) cout << s << '\n';

	return 0;
}