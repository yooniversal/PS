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

double ret;

double getArea(ii a, ii b, ii c) {
    double area = fabs((b.first - a.first) * (c.second - a.second)
                     - (b.second - a.second) * (c.first - a.first)) / 2.0;
    return area;
}

int main() {
    FASTIO;

    int n; cin >> n;
    vii a;
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                ret = max(ret, getArea(a[i], a[j], a[k]));
            }
        }
    }

    cout << fixed << setprecision(9) << ret << '\n';

    return 0;
}