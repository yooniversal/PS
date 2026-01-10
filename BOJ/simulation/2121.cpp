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

int main() {
    FASTIO;

    int N; cin >> N;

    ll A, B; cin >> A >> B;

    map<pair<ll, ll>, bool> mp;

    vector<pair<ll, ll>> points;
    for (int i=0; i<N; i++) {
        ll x, y; cin >> x >> y;
        mp[{x, y}] = true;
        points.emplace_back(x, y);
    }

    int ans = 0;

    for (auto& point : points) {
        ll x = point.first;
        ll y = point.second;

        if (mp[{x + A, y}] && mp[{x, y + B}] && mp[{x + A, y + B}]) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}