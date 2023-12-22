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

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n; cin >> n;
    map<string, bool> chk;
    int ret = 0;
    while (n--) {
        string s; cin >> s;
        if (s == "ENTER") {
            chk.clear();
            continue;
        }

        if (chk[s]) continue;
        chk[s] = true;
        ret++;
    }

    cout << ret << '\n';

    return 0;
}