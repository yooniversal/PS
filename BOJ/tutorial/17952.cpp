//17952
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
    int cur, score, time;
};

stack<P> S;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, ret = 0; cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (!S.empty()) {
            S.top().cur--;
            if (S.top().cur == 0) {
                ret += S.top().score;
                S.pop();
            }
        }
        int mode; cin >> mode;
        if (mode == 1) {
            int s, t; cin >> s >> t;
            S.push({ t, s, t });
        }
    }
    if (!S.empty()) {
        if (S.top().cur == 1) ret += S.top().score;
    }
    cout << ret;

    return 0;
}