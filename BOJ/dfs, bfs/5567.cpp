// 5567
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int ret;
bool chk[505];
vvi a;

void bfs()
{
    queue<ii> q;
    chk[1] = true;
    q.push({ 1, 0 });
    
    while ( !q.empty() )
    {
        auto cur = q.front(); q.pop();

        if ( cur.second == 1 || cur.second == 2 ) ++ret;
        if ( cur.second > 2 ) break;

        printf("cur:%d depth:%d\n", cur.first, cur.second);

        for ( auto &next : a[cur.first] )
        {
            if ( chk[next] ) continue;
            chk[next] = true;
            q.push({ next, cur.second + 1 });
        }
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    a.resize(n + 1);

    while ( m-- )
    {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    bfs();

    cout << ret << '\n';

    return 0;
}
