// 2480
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int cnt(int a, int b, int c)
{
    if ( a == b )
    {
        if ( b == c ) return 2;
        return 1;
    }

    if ( b == c || a == c ) return 1;
    return 0;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, c; cin >> a >> b >> c;
    if ( cnt(a, b, c) == 0 ) cout << max(a, max(b, c)) * 100 << '\n';
    else if ( cnt(a, b, c) == 1 )
    {
        if ( a == b ) cout << 1000 + a * 100 << '\n';
        else if(a ==c) cout << 1000 + a * 100 << '\n';
        else cout << 1000 + b * 100 << '\n';
    }
    else
    {
        cout << 10000 + a * 1000 << '\n';
    }

    return 0;
}
