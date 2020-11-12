//17942
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, m;
vi TIME;
vii adj[MAX];

ll BFS(ll x) {
    ll ret = 0;
    vi cut(n + 1, 0);
    bool chk[MAX] = { 0 };
    queue<int> q;
    for(int i=1; i<=n; ++i)
        if (TIME[i] <= x) {
            chk[i] = true;
            ++ret;
            q.push(i);
        }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto& next : adj[cur]) {
            if (chk[next.first]) continue;
            cut[next.first] += next.second;
            if (TIME[next.first] - cut[next.first] <= x) {
                chk[next.first] = true;
                ++ret;
                q.push(next.first);
            }
        }
    }
    return ret;
}

ll binary_search(ll l, ll r) {
    ll ret = 1;
    while (l <= r) {
        ll mid = (l + r) / 2, tmp = BFS(mid);
        if (tmp < m) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
            ret = mid;
        }
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    TIME.resize(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> TIME[i];
    int r; cin >> r;
    while (r--) {
        int a, b, d; cin >> a >> b >> d;
        adj[a].push_back({ b, d });
    }

    cout << binary_search(1, 100000000);

    return 0;
}