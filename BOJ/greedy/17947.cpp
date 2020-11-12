//17947
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, m, k;
int chk[400001];

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        chk[a] = chk[b] = true;
    }
    int a, b, cur = 0; cin >> a >> b;
    chk[a] = chk[b] = true;
    cur = abs(a % k - b % k); //°ûÃ¶¿ë

    vi card;
    for (int i = 1; i <= 4 * n; ++i) {
        if (chk[i]) continue;
        card.push_back(i % k);
    }
    sort(card.rbegin(), card.rend());

    int ret = 0, len = card.size();
    for (int lo = 0, hi = 1; card[lo] >= cur, hi < len, ret < m-1;) {
        while (hi < len && card[lo] - card[hi] <= cur) ++hi;
        if (hi >= len) break;
        ++ret;
        ++lo; ++hi;
    }
    cout << ret;

    return 0;
}