#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 987654321;
const int MOD = 1000000007;

bool chk[5005];

int main() {
    FASTIO;
    
    int n, k; cin >> n >> k;
    
    vi a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ret = 0;
    for (int i=0, j=a.size()-1; i<n && j>=0 && i<j;) {
        if (a[i] + a[j] > k) {
            j--;
        } else {
            ret++;
            i++; j--;
        }
    }

    cout << ret << '\n';

    return 0;
}