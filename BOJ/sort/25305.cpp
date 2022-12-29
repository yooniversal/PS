// 25305
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vi a(n);
    for ( int i = 0; i < n; ++i ) cin >> a[i];
    sort(a.begin(), a.end());

    cout << a[a.size()-k] << '\n';

    return 0;
}
