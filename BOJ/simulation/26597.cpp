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

const ll INF = 1e18;
const int MOD = 1000000007;

ll minn = -INF, maxx = INF;

int main() {
    FASTIO;

    int q; cin >> q;
    int qIndex = -1;
    bool gotIt = false, paradox = false;
    for (int i=1; i<=q; i++) {
        ll v; char c; cin >> v >> c;
        if (c == '^') {
            minn = max(minn, v + 1LL);
        } else {
            maxx = min(maxx, v - 1LL);
        }

        if (!gotIt && minn == maxx) {
            gotIt = true;
            qIndex = i;
        }
        if (!paradox && minn > maxx) {
            paradox = true;
            qIndex = i;
        }
    }

    if (minn == maxx) {
        cout << "I got it!\n";
        cout << qIndex << '\n';
    } else if (minn > maxx) {
        cout << "Paradox!\n";
        cout << qIndex << '\n';
    } else {
        cout << "Hmm...\n";
    }

    return 0;
}