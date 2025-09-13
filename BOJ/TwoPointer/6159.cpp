#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int n, s; cin >> n >> s;
    vector<int> a;

    for (int i=0; i<n; i++) {
        int v; cin >> v;
        a.push_back(v);
    }
    sort(a.begin(), a.end());

    int ret = 0;

    for (int i=0, j=a.size()-1; i<a.size() && j>=0 && i<j; i++) {
        while (a[i] + a[j] > s) j--;
        if (i >= j) break;

        ret += j-i;
    }

    cout << ret << '\n';

    return 0;
}