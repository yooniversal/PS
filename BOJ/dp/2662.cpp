//2662
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

int n, m;
int a[21][301];
int cache[301][21];
int query[301][21];

int f(int M, int E) {
    if (E == m) {
        if (M == 0) return 0;
        return -INF;
    }
    int& ret = cache[M][E];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i <= M; ++i) {
        if (ret < f(M - i, E + 1) + a[E + 1][i]) {
            query[M][E+1] = i;
            ret = f(M - i, E + 1) + a[E + 1][i];
        }
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int money; cin >> money;
        for (int who = 1; who <= m; ++who) {
            int price; cin >> price;
            a[who][money] = price;
        }
    }

    cout << f(n, 0) << '\n';
    int cur = n, team = 1;
    for (int i = query[cur][team]; team<=m ; i=query[cur][++team]) {
        cur -= i;
        cout << i << ' ';
    }

    return 0;
}