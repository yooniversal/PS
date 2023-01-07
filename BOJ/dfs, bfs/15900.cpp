// 15900
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 9901;

int n;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
vvi a;
bool chk[MAX];


bool bfs()
{
    queue<ii> q;
    q.push({ 1, 0 });
    chk[1] = true;

    int ret = 0;
    while ( !q.empty() )
    {
        auto cur = q.front(); q.pop();
        int x = cur.first, cnt = cur.second;

        bool flag = true;
        for ( auto &next : a[x] )
        {
            if ( chk[next] ) continue;
            chk[next] = true;
            flag = false;
            q.push({ next, cnt + 1 });
        }

        if ( flag )
        {
            ret += cnt;
        }
    }

    if ( ret % 2 ) return true;
    return false;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n+1);

    for ( int i = 0; i < n-1; ++i )
    {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    if ( bfs() ) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
