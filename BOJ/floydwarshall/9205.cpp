//9205
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 105
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dist[MAX][MAX];

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                    dist[i][j] = INF;

        int n; cin >> n;
        vii v;
        for (int i = 0; i < n + 2; ++i) {
            int x, y; cin >> x >> y;
            v.push_back({ x, y });
        }
        for (int i = 0; i < n+1; ++i) {
            for (int j = i + 1; j < n+2; ++j) {
                if (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) <= 1000) {
                    dist[i][j] = 1;
                    dist[j][i] = 1;
                }
            }
        }

        for (int k = 0; k < n + 2; ++k)
            for (int i = 0; i < n + 2; ++i)
                for (int j = 0; j < n + 2; ++j)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        if (dist[0][n+1] != INF) cout << "happy\n";
        else cout << "sad\n";
    }

    return 0;
}