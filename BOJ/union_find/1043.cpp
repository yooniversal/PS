//1043
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int uni[51];

int find(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find(uni[a]);
}

void makeUnion(int a, int b) {
	a = find(a), b = find(b);
	if (a < b) uni[b] = a;
	else uni[a] = b;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 51; ++i) uni[i] = i;
	int n, m; cin >> n >> m;
	int	k; cin >> k;
	vi kp(k);
	for (int i = 0; i < k; ++i) {
		cin >> kp[i];
		if (i > 0) makeUnion(kp[0], kp[i]);
	}

	int ret = 0;
	vvi p(m);
	for (int i = 0; i < m; ++i) {
		int N; cin >> N;
		p[i].resize(N);
		for (int j = 0; j < N; ++j) {
			cin >> p[i][j];
			if (j > 0) makeUnion(p[i][0], p[i][j]);
		}
	}
	
	if (kp.size() == 0) cout << m << '\n';
	else {
		for (int i = 0; i < m; ++i) {
			bool flag = true;
			for (int person : p[i]) {
				if (find(person) == find(kp[0])) {
					flag = false;
					break;
				}
			}
			if (flag) ++ret;
		}
		cout << ret << '\n';
	}

	return 0;
}