//17954
//non-complete
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
    sort(card.begin(), card.end());
    
    for (int r : card) cout << r << ' ';
    cout << '\n';

    int ret = 0, here=0;
    auto it = lower_bound(card.begin() + 1, card.end(), card[0] + cur + 1);
    here = it - card.begin();
    memset(chk, false, sizeof(chk));
    int len = card.size();
    if (here < len) {
        chk[0] = chk[here] = true;
        ++ret;
        for (int lo = 1, hi = here + 1; hi < len;) {
            while (chk[lo]) ++lo;
            while (hi < len && (lo >= hi || chk[hi])) ++hi;
            while (hi < len && card[hi] - card[lo] <= cur) ++hi;
            printf("lo:%d hi:%d\n", lo, hi);
            if (hi >= len) break;
            chk[lo] = chk[hi] = true;
            ++ret;
            ++lo; ++hi;
        }
    }
    cout << min(ret, m-1);

    return 0;
}