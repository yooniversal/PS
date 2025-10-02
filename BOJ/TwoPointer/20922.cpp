#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int INF = 987654321;
const int MOD = 1000000007;

int n, k;
vi a;
int numberDupCnt[100005];

int main() {
    FASTIO;
    
    cin >> n >> k;
    a.resize(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int ret = 0;
    for (int i=0, j=0; i<=j && i<n && j<n;) {
        if (numberDupCnt[a[j]] < k) {
            numberDupCnt[a[j]]++;
            ret = max(ret, j - i + 1);
            j++;
        } else {
            numberDupCnt[a[i]]--;
            i++;
        }
    }

    cout << ret << '\n';

    return 0;
}