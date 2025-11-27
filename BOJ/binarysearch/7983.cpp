#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

bool isPass(vii& a, int currentDay) {
    for (auto& task : a) {
        int targetDay = task.first;
        int needTime = task.second;

        if (currentDay + needTime > targetDay) return false;
        currentDay += needTime;
    }

    return true;
}

int main() {
    FASTIO;

    int n; cin >> n;
    int maxTime = 0;
    vii a(n);
    for (int i=0; i<n; i++) {
        int d, t; cin >> d >> t;
        a[i] = {t, d};
        maxTime = max(maxTime, t);
    }
    sort(a.begin(), a.end());

    int l=0, r=maxTime;
    int ret = 0;
    while (l <= r) {
        int m = (l+r) / 2;
        if (isPass(a, m)) {
            ret = max(ret, m);
            l = m+1;
        } else {
            r = m-1;
        }
    }

    cout << ret << '\n';

    return 0;
}