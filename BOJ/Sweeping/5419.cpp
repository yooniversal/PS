//5419

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 987654321
#define MAX 75001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll tree[MAX];
int n;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

void update(int idx, ll diff) {
    for (int i = idx; i <= n; i += (i & -i)) {
        tree[i] += diff;
    }
}

ll sum(int idx) {
    ll ret = 0;
    for (int i = idx; i > 0; i -= (i & -i)) {
        ret += tree[i];
    }
    return ret;
}

void initialize() {
    memset(tree, 0, sizeof(tree));
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        initialize();

        cin >> n;
        vector<pair<ll, ll>> tmp(n);
        for (int i = 0; i < n; i++) {
            ll fir, sec; cin >> fir >> sec;
            tmp[i] = { fir, sec };
        }

        sort(tmp.begin(), tmp.end(), cmp);

        for (ll i = 0; i < n; i++) {
            tmp[i].second = i+1;
        }
        
        sort(tmp.begin(), tmp.end());

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += sum(tmp[i].second-1);
            update(tmp[i].second, 1);
        }
        
        cout << ans << '\n';
    }

    return 0;
}