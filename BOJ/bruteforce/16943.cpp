//16943
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 5005, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a; int b; cin >> a >> b;
	sort(a.begin(), a.end());

	int ret = 0;
	do {
		if (a[0] == '0') continue;
		int ia = stoi(a);
		if(ia <= b) ret = max(ret, ia);
	} while (next_permutation(a.begin(), a.end()));
	
	if (ret == 0) cout << -1 << '\n';
	else cout << ret << '\n';

	return 0;
}