// 11478
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

    string s; cin>>s;
    map<string, bool> chk;
    int ret = 0;

    for (int i = 0; i < s.size(); ++i) {
        for (int sz = 1; i + sz <= s.size(); ++sz) {
            string sub_s = s.substr(i, sz);
            if(chk[sub_s])
                continue;
            chk[sub_s] = true;
            ++ret;
        }
    }

    cout << ret << '\n';

    return 0;
}
