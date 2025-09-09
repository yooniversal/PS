#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
const int MOD = 1000000007;

int main() {
    FASTIO;

    int x; cin >> x;
    int bnp = 0, timing = 0;
    int remainBnp = x, remainTiming = x;
    int prev = -1, ascCnt = 0, descCnt = 0;
    for (int i=0; i<14; i++) {
        int v; cin >> v;
        if (i > 0) {
            if (prev < v) {
                ascCnt++; descCnt = 0;
            } else if (prev > v) {
                ascCnt = 0; descCnt++;
            }
        }

        if (bnp == 0 && remainBnp >= v) {
            bnp = x / v;
            remainBnp = x - x / v * v;
        }
        
        if (ascCnt >= 3) {
            remainTiming += timing * v;
            timing = 0;
        } else if (descCnt >= 3) {
            timing += remainTiming / v;
            remainTiming -= remainTiming / v * v;
        }

        prev = v;

        if (i == 13) {
            bnp = bnp * v + remainBnp;
            timing = timing * v + remainTiming;
        }
    }

    if (bnp > timing) cout << "BNP\n";
    else if (timing > bnp) cout << "TIMING\n";
    else cout << "SAMESAME\n";

    return 0;
}