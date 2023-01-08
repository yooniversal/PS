// 1449
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500005, INF = 1000000001, MOD = 9901;

int N, L;
vi a;

int dfs(int cur)
{
    int next = -1;
    for ( int i = cur + 1; i < a.size(); ++i )
    {
        if ( a[i] <= (a[cur] + L - 1) ) continue;
        next = i;
        break;
    }
    
    if(next != -1) return dfs(next) + 1;
    return 0;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> L;
    a.resize(N);
    for ( int i = 0; i < N; ++i )
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    cout << dfs(0)+1 << '\n';

    return 0;
}
