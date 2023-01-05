// 1303
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
char a[101][101];
bool chk[101][101];

bool OOB(int x, int y)
{
    if ( x < 0 || x >= n || y < 0 || y >= m ) return true;
    return false;
}

void bfs(int sx, int sy)
{
    queue<ii> q;
    q.push({ sx, sy });
    chk[sx][sy] = true;
    char team = a[sx][sy];

    int cnt = 0;
    while ( !q.empty() )
    {
        auto cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;

        ++cnt;

        for ( int i = 0; i < 4; ++i )
        {
            int nx = x + dx[i], ny = y + dy[i];
            if ( OOB(nx, ny) ) continue;
            if ( chk[nx][ny] || a[nx][ny] != team ) continue;
            chk[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
    
    if ( team == 'W' ) ret += cnt * cnt;
    else ret2 += cnt * cnt;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    for ( int i = 0; i < n; ++i ) for ( int j = 0; j < m; ++j )
    {
        cin >> a[i][j];
    }

    for ( int i = 0; i < n; ++i ) for ( int j = 0; j < m; ++j )
    {
        if ( chk[i][j] ) continue;
        bfs(i, j);
    }

    cout << ret << " " << ret2 << '\n';

    return 0;
}
