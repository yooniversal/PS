//19566

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
#define MAXSIZE 2000001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; ll k; cin >> n >> k;
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) cin >> pre[i];
    for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];

    map<ll, ll> key;

    ll res = 0;
    for (ll i = 1; i <= n; i++) {
        key[pre[i - 1] - k * (i - 1)]++;
        res += key[pre[i] - k * i];
    }

    cout << res;


    return 0;
}