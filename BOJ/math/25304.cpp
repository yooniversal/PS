// 25304
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

    ll x; cin >> x;
    int n; cin >> n;
    
    ll sum = 0;
    for ( int i = 0; i < n; ++i )
    {
        int a, b; cin >> a >> b;
        sum += a * b;
    }

    if ( sum == x ) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
