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

int n, m;
int a[105][75];
bool visited[105][75];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool OOB(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= m;
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

    int ret = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visited[i][j]) continue;
            visited[i][j] = true;

            int h = a[i][j];
            bool isPeak = true;

            queue<pair<int,int>> q;
            q.push({i, j});

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                for (int d=0; d<8; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (OOB(nx, ny)) continue;
                    if (a[nx][ny] > h) isPeak = false;

                    if (!visited[nx][ny] && a[nx][ny] == h) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            if (isPeak) ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}