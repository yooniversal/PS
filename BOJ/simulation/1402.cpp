#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int cnt[101][101];

int main() {
    FASTIO;

    int n, m; cin >> n >> m;
    for (int i=0; i<n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        for (int x=a; x<=c; x++) {
            for (int y=b; y<=d; y++) {
                cnt[x][y]++;
            }
        }
    }

    int ret = 0;
    for (int i=1; i<=100; i++) for (int j=1; j<=100; j++) {
        if (cnt[i][j] > m) {
            ret++;
        }
    }

    cout << ret << '\n';

    return 0;
}