//16924
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

struct P {
    int x, y, s;
};

int n, m, dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
char a[101][101];
bool chk[101][101];

bool OOB(int x, int y) { return x <= 0 || x > n || y <= 0 || y > m; }

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        cin >> a[i][j];
        if (a[i][j] == '*') ++sum;
    }
    
    vector<P> ret;
    int crosses = 0;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        if (a[i][j] == '.') continue;
        bool flag = false;
        for (int k = 1; ; ++k) {
            for (int d = 0; d < 4; ++d) {
                int nx = i + dx[d]*k, ny = j + dy[d]*k;
                if (OOB(nx, ny) || a[nx][ny] == '.') {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                if (k == 1) break;
                for (int K = 0; K < k; ++K) {
                    for (int d = 0; d < 4; ++d) {
                        int nx = i + dx[d] * K, ny = j + dy[d] * K;
                        chk[nx][ny] = true;
                    }
                }
                --k;
                ++crosses;
                ret.push_back({ i,j,k });
                break;
            }
        }
    }

    int visited = 0;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        if (a[i][j] == '*' && chk[i][j]) ++visited;
    }

    if (sum == visited) {
        cout << crosses << '\n';
        for (auto& cur : ret)
            cout << cur.x << ' ' << cur.y << ' ' << cur.s << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}