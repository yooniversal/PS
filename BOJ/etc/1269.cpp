// 1269
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

    int s1, s2;
    cin >> s1 >> s2;

    map<ll, bool> chk;
    for (int i = 0; i<s1; ++i) {
        int v; cin >> v;
        chk[v] = true;
    }

    int cnt = 0;
    for (int i = 0; i < s2; ++i) {
        int v;
        cin >> v;
        if(chk[v])
            ++cnt;
    }

    cout << s1+s2 - 2*cnt << '\n';

    return 0;
}
