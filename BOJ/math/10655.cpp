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

ii a[100001];

int dist(int i, int j) {
    return abs(a[i].first - a[j].first)
         + abs(a[i].second - a[j].second);
}

int main() {
    FASTIO;

    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i].first >> a[i].second;

    int total = 0;
    for (int i=1; i<n; i++) {
        total += dist(i, i+1);
    }

    int ret = INF;
    for (int i=2; i<n; i++) {
        int part = dist(i-1, i) + dist(i, i+1) - dist(i-1, i+1);
        ret = min(ret, total - part);
    }

    cout << ret << '\n';

    return 0;
}