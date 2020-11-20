//14495
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 100005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll dp[117];

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    dp[1] = dp[2] = dp[3] = 1;
    for (int i = 4; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 3];
    cout << dp[n];

    return 0;
}