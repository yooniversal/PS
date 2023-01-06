// 13565
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n, m;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int ret, ret2;
char a[1005][1005];
bool chk[1005][1005];

bool OOB(int x, int y)
{
    if ( x < 0 || x >= n || y < 0 || y >= m ) return true;
    return false;
}

bool bfs(int sx, int sy)
{
    queue<ii> q;
    q.push({ sx, sy });
    chk[sx][sy] = true;

    while ( !q.empty() )
    {
        auto cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;

        if ( x == n - 1 ) return true;

        for ( int i = 0; i < 4; ++i )
        {
            int nx = x + dx[i], ny = y + dy[i];
            if ( OOB(nx, ny) ) continue;
            if ( chk[nx][ny] || a[nx][ny] == '1' ) continue;
            chk[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

    return false;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for ( int i = 0; i < n; ++i ) for ( int j = 0; j < m; ++j )
    {
        cin >> a[i][j];
    }

    bool ret = false;
    for ( int j = 0; j < m; ++j )
    {  
        if ( chk[0][j] || a[0][j] == '1' ) continue;
        if ( bfs(0, j) == true )
        {
            ret = true;
            break;
        }
    }

    if ( ret ) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
