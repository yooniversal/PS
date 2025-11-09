#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int n, m;
int cache[25][205];
vii bag;

int f(int cur, int days) {
    if (cur >= m || days <= 0) return 0;
    int& ret = cache[cur][days];
    if (ret != -1) return ret;
    ret = 0;

    if (bag[cur].first <= days) {
        ret = max(ret, f(cur+1, days - bag[cur].first) + bag[cur].second);
    }
    ret = max(ret, f(cur+1, days));

    return ret;
}

int main() {
    FASTIO;

    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int size, value; cin >> size >> value;
        bag.push_back({size, value});
    }

    cout << f(0, n) << '\n';

    return 0;
}