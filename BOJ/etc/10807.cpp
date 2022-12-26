// 10807
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
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

    int n, target;
    cin >> n;

    vi a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cin >> target;
    int ret = 0;

    for (auto &v : a)
    {
        if (v == target)
            ++ret;
    }

    cout << ret << '\n';

    return 0;
}
