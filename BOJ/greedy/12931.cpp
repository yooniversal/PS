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

bool isFinish(vi& a) {
    for (int i=0; i<a.size(); i++) {
        if (a[i] == 0) continue;
        return false;
    }
    return true;
}

int deleteOdd(vi& a) {
    int ret = 0;
    for (int i=0; i<a.size(); i++) {
        if (a[i] % 2 != 0) {
            ret++;
            a[i]--;
        }
    }
    return ret;
}

void divideHalf(vi& a) {
    for (int i=0; i<a.size(); i++) a[i] /= 2;
}

int main() {
    FASTIO;

    int n; cin >> n;
    vi a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int ret = 0;
    while (!isFinish(a)) {
        int deletedOddCnt = deleteOdd(a);
        if (deletedOddCnt > 0) {
            ret += deletedOddCnt;
        } else {
            divideHalf(a);
            ret++;
        }
    }

    cout << ret << '\n';

    return 0;
}