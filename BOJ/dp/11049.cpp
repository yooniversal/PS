//11049
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 520
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[MAX][MAX];
vii M;

ll multiply(int a, int b, int c) {
    if (a == c) return INF;
    return 1LL * M[a].first * M[b].second * M[c].second;
}

ll f(int a, int b) {
    if (a == b) return 0;
    ll& ret = cache[a][b];
    if (ret != -1) return ret;

    ret = INF;
    for (int i = a; i < b; ++i)
        ret = min(ret, f(a, i) + f(i+1, b) + multiply(a, i, b));
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        M.push_back({ a, b });
    }

    cout << f(0, n - 1);

    return 0;
}