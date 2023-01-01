// 24416
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int ret, ret2;
int fib_arr[45];

int recursive_fib(int n)
{
    if ( n == 1 || n == 2 )
    {
        ++ret;
        return 1;
    }
    return recursive_fib(n - 1) + recursive_fib(n - 2);
}

int dp_fib(int n)
{
    if ( n == 1 || n == 2 ) return 1;
    int &fib = fib_arr[n];
    if ( fib != -1 ) return fib;
    ++ret2;
    fib = dp_fib(n - 1) + dp_fib(n - 2);
    return fib;

}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    memset(fib_arr, -1, sizeof(fib_arr));

    int n; cin >> n;
    recursive_fib(n);
    dp_fib(n);

    cout << ret << " " << ret2 << '\n';

    return 0;
}
