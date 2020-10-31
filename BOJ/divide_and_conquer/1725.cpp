//1725
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vector<ll> a;

ll query(int start, int end) {
    ll ret = 0;
    if (start == end)  return a[start];
    int mid = (start + end) / 2;
    ret = max(query(start, mid), query(mid + 1, end));

    int lo = mid, hi = mid + 1;
    ll height = min(a[lo], a[hi]);
    ret = max(ret, height * 2);

    while (start < lo || hi < end) {
        if (hi < end && (lo == start || a[lo - 1] < a[hi + 1])) {
            ++hi;
            height = min(height, a[hi]);
        }
        else {
            --lo;
            height = min(height, a[lo]);
        }
        ret = max(ret, height * (hi - lo + 1) * 1LL);
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << query(0, n - 1);

    return 0;
}