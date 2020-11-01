//14225
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

bool chk[2000001];
vi a;

void solve(string s) {
	do {
		int tmp = 0;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == '1')
				tmp += a[i];
		chk[tmp] = true;
	} while (next_permutation(s.begin(), s.end()));
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	string s(n, '0');
	for (int i = n - 1; i >= 0; --i) {
		s[i] = '1';
		solve(s);
	}
	
	for(int i=1; i<=2000000; ++i)
		if (!chk[i]) {
			cout << i;
			break;
		}

	return 0;
}