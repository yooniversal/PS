//7570
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dp[MAX];

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        dp[x] = dp[x - 1] + 1;
        ret = max(ret, dp[x]);
    }
    cout << n-ret;

	return 0;
}