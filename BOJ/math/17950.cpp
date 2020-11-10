//17950
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int h, x; cin >> h >> x;
    ll ret = 0, size = 1;
    for (int i = 1; i <= h; ++i) {
        ll cnt; cin >> cnt;
        size *= x;
        ret += cnt * size;
    }
    cout << ret;

    return 0;
}