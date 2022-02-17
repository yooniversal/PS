//1405
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
double dir[4], ret = 1.0;
bool chk[31][31];

void solve(int cnt, int x, int y, double prob) {
    if (cnt >= n) return;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (chk[nx][ny]) {
            ret -= prob * dir[i];
            continue;
        }
        chk[nx][ny] = true;
        solve(cnt+1, nx, ny, prob * dir[i]);
        chk[nx][ny] = false;
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < 4; ++i) {
        cin >> dir[i];
        dir[i] *= 0.01;
    }

    chk[15][15] = true;

    solve(0, 15, 15, 1.0);

    cout.precision(10);
    cout << ret << '\n';

    return 0;
}