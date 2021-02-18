//2138
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n;
int dx[] = { -1,0,1 };

bool OOB(int x) { return x<0 || x>=n; }

int solve(vector<char> a, vector<char>& b, int ver) {
	int ret = 0;
	if (ver == 0) {
		for (int i = 0; i < 2; ++i)
			a[i] = a[i] == '0' ? '1' : '0';
		++ret;
	}
	
	for (int i = 1; i < n; ++i) {
		if (a[i - 1] != b[i - 1]) {
			for (int j = 0; j < 3; ++j) {
				int nx = i + dx[j];
				if (OOB(nx)) continue;
				a[nx] = a[nx] == '0' ? '1' : '0';
			}
			++ret;
		}
	}

	bool fin = true;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			fin = false;
			break;
		}
	}

	return fin ? ret : -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	vector<char> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	
	int ret = solve(a, b, 0), ret2 = solve(a, b, 1);
	if (ret == -1 || ret2 == -1) {
		if (ret == -1) cout << ret2 << '\n';
		else cout << ret << '\n';
	}
	else {
		cout << min(ret, ret2) << '\n';
	}

	return 0;
}