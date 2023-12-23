#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

map<string, bool> chk;
int cnt;

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n; cin >> n;
    bool flag = true;
    while (n--) {
        string u, v; cin >> u >> v;
        if (flag) {
            if (u != "ChongChong" && v != "ChongChong") continue;
            flag = false;

            if (u == "ChongChong") {
                chk[u] = true;
                cnt++;
            }
            if (v == "ChongChong") {
                chk[v] = true;
                cnt++;
            }
        }

        if (!chk[u] && !chk[v]) continue;

        if (!chk[u]) {
            chk[u] = true;
            cnt++;
        }
        if (!chk[v]) {
            chk[v] = true;
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}