#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

int n, k;
vector<ii> a;
vector<int> pick;
int ret = INF;

int dist(ii& p, ii& q) {
    return abs(p.first - q.first) + abs(p.second - q.second);
}

void dfs(int idx, int cnt) {
    if (cnt == k) {
        int cur = 0;

        for (int i=0; i<n; i++) {
            int d = INF;
            for (int target : pick) d = min(d, dist(a[i], a[target]));
            cur = max(cur, d);
        }
        ret = min(ret, cur);

        return;
    }

    if (idx < n) {
        pick.push_back(idx);
        dfs(idx+1, cnt+1);
        pick.pop_back();

        dfs(idx+1, cnt);
    }
}

int main() {
    FASTIO;

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
    }

    dfs(0, 0);
    cout << ret << '\n';

    return 0;
}