//17949
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll ts[16];

ll convert(char a) {
    if (isdigit(a)) return a - '0';
    return a - 'a' + 10;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ts[0] = 1;
    for (int i = 1; i < 16; ++i)
        ts[i] = ts[i - 1] * 16;

    string num; int n, now=0; cin >> num >> n;
    while (n--) {
        string type; cin >> type;
        if (type[0] == 'c') {
            cout << convert(num[now]) * 16 + convert(num[now+1]) * 1 << ' ';
            now += 2;
        }
        else if (type[0] == 'i') {
            ll ret = 0;
            for (int i = now+7, j = 0; i >= now, j <= 7; --i, ++j) {
                ret += convert(num[i]) * ts[j];
            }
            cout << ret << ' ';
            now += 8;
        }
        else {
            ll ret = 0;
            for (int i = now+15, j = 0; i >= now, j <= 15; --i, ++j) {
                ret += convert(num[i]) * ts[j];
            }
            cout << ret << ' ';
            now += 16;
        }
    }

    return 0;
}