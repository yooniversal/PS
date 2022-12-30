// 2525
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

    int a, b, c; cin >> a >> b >> c;
    b += c;
    a += b / 60;
    b %= 60;
    a %= 24;

    cout << a << " " << b << '\n';

    return 0;
}
