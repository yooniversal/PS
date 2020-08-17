//2836

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
#define INF (1e9+1)
#define MAXSIZE 500001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vector<pair<ll, ll>> lines;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; int m; cin >> n >> m;
    lines.resize(n);

    for (int i = 0; i < n; i++) {
        ll fir, sec; cin >> fir >> sec;
        //역으로 가는 방향만
        if (fir > sec) {
            swap(fir, sec);
            lines[i] = { fir, sec };
        }
    }

    sort(lines.begin(), lines.end());

    ll left = -INF, right = -INF, reverse_len = 0;
    for (int i = 0; i < lines.size(); i++) {
        if (right < lines[i].first) {
            reverse_len += right - left;
            left = lines[i].first;
            right = lines[i].second;
        }
        else {
            right = max(right, lines[i].second);
        }
    }
    reverse_len += right - left;
    reverse_len *= 2;

    ll ans = m + reverse_len;

    cout << ans;

    return 0;
}