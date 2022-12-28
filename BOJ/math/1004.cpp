// 1004
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct Circle
{
    int x, y;
    double r;
};

double d(ii a, ii b)
{
    int x_diff = a.first - b.first;
    int y_diff = a.second - b.second;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

bool inCircle(int x, int y, Circle &c)
{
    if ( d({ x, y }, { c.x, c.y }) < c.r )
        return true;
    return false;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while ( t-- )
    {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        int n; cin >> n;
        vector<Circle> c(n);
        for ( int i = 0; i < n; ++i )
        {
            cin >> c[i].x >> c[i].y >> c[i].r;
        }

        bool chk_s[51], chk_e[51];
        memset(chk_s, false, sizeof(chk_s));
        memset(chk_e, false, sizeof(chk_e));

        for ( int i = 0; i < n; ++i )
        {
            if ( inCircle(sx, sy, c[i]) )
                chk_s[i] = true;
        }

        for ( int i = 0; i < n; ++i )
        {
            if ( inCircle(ex, ey, c[i]) )
                chk_e[i] = true;
        }

        int ret = 0;
        for ( int i = 0; i < n; ++i )
        {
            if ( chk_s[i] == chk_e[i] ) continue;
            ret++;
        }

        cout << ret << '\n';
    }

    return 0;
}
