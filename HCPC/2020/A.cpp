#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	if (n == 1) cout << 2 * k;
	else cout << n * k;

	return 0;
}