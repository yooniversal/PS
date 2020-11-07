//4883
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 501
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[100001][4];
int a[100001][4];
int n;

int f(int row, int col) {
    if (row == n) {
        if (col == 1) return a[row][col] + a[row][col + 1];
        else if(col == 2) return a[row][col];
        return INF;
    }
    int& ret = cache[row][col];
    if (ret != -1) return ret;
    ret = INF;
    if (col == 1) {
        ret = min(ret, f(row + 1, col) + a[row][col]);
        ret = min(ret, f(row + 1, col + 1) + a[row][col]);
        ret = min(ret, f(row, col + 1) + a[row][col]);
    }
    else if (col == 2) {
        ret = min(ret, f(row + 1, col) + a[row][col]);
        ret = min(ret, f(row + 1, col + 1) + a[row][col]);
        ret = min(ret, f(row, col + 1) + a[row][col]);
        ret = min(ret, f(row + 1, col - 1) + a[row][col]);
    }
    else {
        ret = min(ret, f(row + 1, col) + a[row][col]);
        ret = min(ret, f(row + 1, col - 1) + a[row][col]);
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    while (1) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        if (n == 0) break;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j) {
                cin >> a[i][j];
            }
        }
        cout << ++cnt << ". " << f(1, 2) << '\n';
    }

    return 0;
}