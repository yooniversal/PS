#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[51];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) cin >> d[i];
		int ret = 0, st = -1;
		for (int i = 0; i < n; ++i) {
			if (st == -1 && d[i] == 1) st = i;
			else {
				if (d[i] == 1) {
					ret += i - st - 1;
					st = i;
				}
			}
		}
		cout << ret << '\n';
	}

	return 0;
}