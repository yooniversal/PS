//2011
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 5001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

string s;
ll cache[MAX];

ll f(int cur) {
    if (cur == s.size()) return 1;
    if (s[cur] == '0') return 0;
    ll& ret = cache[cur];
    if (ret != -1) return ret;
    ret = 0;
    if (cur != s.size() - 1) {
        int tmp = (s[cur] - '0') * 10 + (s[cur + 1] - '0');
        if (10 <= tmp && tmp <= 26) ret += f(cur + 2) % MOD;
    }
    ret += f(cur + 1) % MOD;
    ret %= MOD;
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));
    cin >> s;
    cout << f(0);

    return 0;
}