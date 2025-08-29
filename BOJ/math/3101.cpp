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

int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0}; // LRUD

ll getValue(ll n, ll x, ll y) {
    ll r = x + y + 1; // 대각선 행번호

    if (r <= n) {
        if (r % 2 == 1) {
            // 왼쪽부터 시작
            return r * (r-1) / 2 + 1 + y;
        }

        // 오른쪽부터 시작
        return r * (r-1) / 2 + 1 + x;
    }

    ll beforeBase = 0;
    if (r == n+1) beforeBase = r * (r-1) / 2 + 1;
    else beforeBase = n * (n+1) / 2 + 1 + (r-n-1)*(3*n-r) / 2;

    if (r % 2 == 1) {
        // 왼쪽부터 시작
        return beforeBase + (n-x-1);
    }
    
    // 오른쪽부터 시작
    return beforeBase + (n-y-1);
}

int main() {
    FASTIO;
    
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    
    ll ret = 1LL;

    ll x = 0, y = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'L') {
            x += dx[0]; y += dy[0];
        } else if (s[i] == 'R') {
            x += dx[1]; y += dy[1];
        } else if (s[i] == 'U') {
            x += dx[2]; y += dy[2];
        } else {
            x += dx[3]; y += dy[3];
        }

        ret += getValue(n, x, y);
    }

    cout << ret << '\n';

    return 0;
}