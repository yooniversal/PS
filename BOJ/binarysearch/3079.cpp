#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int n, m;
vi times;

ull getPassedPersonCnt(ull targetTime) {
    ull ret = 0;
    for (int i=0; i<n; i++) ret += targetTime / times[i];
    return ret;
}

ull getShortestTime() {
    ull ret = 0;
    ull l = 1, r = 1e19;

    while (l <= r) {
        ull targetTime = (l+r) / 2;
        ull passedPersonCnt = getPassedPersonCnt(targetTime);
        if (passedPersonCnt >= m) {
            ret = targetTime;
            r = targetTime-1;
        } else {
            l = targetTime+1;
        }
    }

    return ret;
}

int main() {
    FASTIO;

    cin >> n >> m;
    times.resize(n);
    for (int i=0; i<n; i++) cin >> times[i];

    cout << getShortestTime() << '\n';

    return 0;
}