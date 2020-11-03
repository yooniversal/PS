//5525
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    string s; cin >> s;
    vi a;
    bool prev = false;
    int cnt = 0, skipcnt = 0;
    for (int i = 1; i < m-1; ++i) {
        if (s[i] != 'O') {
            ++skipcnt;
            if (skipcnt >= 2) {
                skipcnt = 0;
                a.push_back(cnt);
                cnt = 0;
                prev = false;
            }
            continue;
        }
        skipcnt = 0;
        if (!prev) {
            if (s[i - 1] == 'I' && s[i + 1] == 'I') {
                prev = true;
                ++cnt;
            }
        }
        else {
            if (s[i - 1] == 'I' && s[i + 1] == 'I') {
                ++cnt;
            }
            else {
                prev = false;
                a.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if (cnt) a.push_back(cnt);

    int ret = 0;
    for (int aa : a)
        if (aa - (n - 1) > 0)
            ret += aa - (n - 1);
    cout << ret;

    return 0;
}