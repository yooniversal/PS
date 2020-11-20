//2157
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

int dp[301][301];
int score[301][301];

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(score, -1, sizeof(score));
    memset(dp, -1, sizeof(dp));
    int n, m, k; cin >> n >> m >> k;
    while (k--) {
        int a, b, c; cin >> a >> b >> c;
        score[a][b] = max(score[a][b], c);
    }

    dp[1][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (score[i][j] == -1) continue;
            for (int M = 2; M <= m; ++M) {
                if (dp[i][M - 1] == -1) continue;
                dp[j][M] = max(dp[j][M], dp[i][M - 1] + score[i][j]);
            }
        }
    }
    
    int ret = 0;
    for (int i = 2; i <= m; ++i) {
        ret = max(ret, dp[n][i]);
    }
    cout << ret;

    return 0;
}