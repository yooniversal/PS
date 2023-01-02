// 2559
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int a[MAX], sum[MAX];

int main()
{
    cin.tie(nullptr);   
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    for ( int i = 0; i < n; ++i )
    {
        cin >> a[i];
    }

    sum[0] = a[0];
    for ( int i = 1; i < n; ++i )
    {
        sum[i] = sum[i - 1] + a[i];
    }

    /*for ( int i = 0; i < n; ++i )
        printf("sum[%d]:%d\n", i, sum[i]);*/

    int ret = sum[k - 1];
    for ( int i = k; i < n; ++i )
    {
        //printf("ret:%d sum[%d]-sum[%d] = %d - %d = %d\n", ret, i, i - k, sum[i], sum[i - k]);
        if ( ret < sum[i] - sum[i - k] )
        {
            ret = sum[i] - sum[i - k];
        }
    }

    if ( n == k ) ret = sum[n - 1];

    cout << ret << '\n';

    return 0;
}
