//17953
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, m;
int cache[100001][12];
int dessert[11][100001];

int f(int cur, int prev) {
    if (cur == n) return 0;
    int& ret = cache[cur][prev];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < m; ++i) {
        if(prev != i)
            ret = max(ret, f(cur + 1, i) + dessert[i][cur]);
        else
            ret = max(ret, f(cur + 1, i) + dessert[i][cur]/2);
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dessert[i][j];
    cout << f(0, 11);

    return 0;
}