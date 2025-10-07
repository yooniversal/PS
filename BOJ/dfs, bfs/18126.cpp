#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int INF = 987654321;
const int MOD = 1000000007;

vii e[5005];
ll dist[5005];
bool chk[5005];

void DFS(int cur, ll sumDist) {
    for (auto& next : e[cur]) {
        if (chk[next.first]) continue;
        chk[next.first] = true;
        dist[next.first] = max(dist[next.first], sumDist + next.second);
        DFS(next.first, sumDist + next.second);
    }
}

int main() {
    FASTIO;

    int n; cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b, d; cin >> a >> b >> d;
        e[a].push_back({b, d});
        e[b].push_back({a, d});
    }

    chk[1] = true;
    DFS(1, 0);

    ll ret = 0;
    for (int i=1; i<=n; i++) {
        ret = max(ret, dist[i]);
    }

    cout << ret << '\n';

    return 0;
}