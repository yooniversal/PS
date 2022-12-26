// 2566
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

    int ret = -1;
    int x = 0, y = 0;
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            int v;
            cin >> v;
            if (ret < v)
            {
                ret = v;
                x = i;
                y = j;
            }
        }
    }

    cout << ret << '\n'
         << x << " " << y << '\n';

    return 0;
}
