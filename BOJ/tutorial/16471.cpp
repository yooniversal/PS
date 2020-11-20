//16471
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 605
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vi J(n), S(n);
	for (int i = 0; i < n; ++i) cin >> J[i];
	for (int i = 0; i < n; ++i) cin >> S[i];
	sort(J.rbegin(), J.rend());
	sort(S.rbegin(), S.rend());

	int ret = 0;
	for (int i = 0, j = 0; i < n && j < n;) {
		if (J[i] >= S[j]) ++i;
		else {
			++ret; ++i; ++j;
		}
	}
	if (ret >= (n + 1) / 2) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}