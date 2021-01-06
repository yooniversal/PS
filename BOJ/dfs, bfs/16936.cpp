//16936
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

int n;
bool chk[101];
vi a[101];
vector<ll> ret, arr;

void DFS(int cur, int cnt) {
    if (cnt == n) {
        for (auto& r : ret) cout << r << ' ';
        cout << '\n';
        exit(0);
    }

    for (auto& next : a[cur]) {
        if (chk[next]) continue;
        chk[next] = true;
        ret.emplace_back(arr[next]);
        DFS(next, cnt + 1);
        ret.pop_back();
        chk[next] = false;
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((arr[i] % 3 == 0 && arr[i] / 3 == arr[j]) || arr[i] * 2 == arr[j])
                a[i].emplace_back(j);
        }
    }

    for (int i = 0; i < n; ++i) {
        chk[i] = true;
        ret.emplace_back(arr[i]);
        DFS(i, 1);
        ret.pop_back();
        chk[i] = false;
    }

    return 0;
}