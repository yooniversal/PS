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

int main() {
    FASTIO;

    int n; cin >> n;
    vi a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vi frontSum(n, 0), backSum(n, 0);
    frontSum[0] = a[0];
    backSum[n-1] = a[n-1];
    for (int i=1; i<n; i++) frontSum[i] = frontSum[i-1] + a[i];
    for (int i=n-2; i>=0; i--) backSum[i] = backSum[i+1] + a[i];

    int ret = 0;
    
    for (int r=1; r<n-1; r++) {
        int leftSum = frontSum[n-1] - a[r] - a[0];
        int rightSum = frontSum[n-1] - frontSum[r];
        ret = max(ret, leftSum + rightSum);
    }

    for (int l=n-2; l>=1; l--) {
        int leftSum = backSum[0] - a[l] - a[n-1];
        int rightSum = backSum[0] - backSum[l];
        ret = max(ret, leftSum + rightSum);
    }

    int l=0, r=n-1;
    int sum = 0;
    for (int i=1; i<n-1; i++) {
        ret = max(ret, (frontSum[i] - a[0]) + (backSum[i] - a[n-1]));
    }

    cout << ret << '\n';

    return 0;
}