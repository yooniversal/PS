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

map<string, int> cache;

string process(string& s) {
    string minn = s;
    sort(minn.begin(), minn.end());
    string maxx = minn;
    reverse(maxx.begin(), maxx.end());

    string ret = to_string(abs(stoi(maxx) - stoi(minn)));
    if (ret.size() < 4) ret = string(4 - ret.size(), '0') + ret;
    return ret;
}

int main() {
    FASTIO;

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        int cnt = 0;
        
        while (s != "6174") {
            if (cache[s] != 0) break;
            s = process(s);
            cnt++;
        }

        if (cache[s] == 0) cache[s] = cnt;

        cout << cnt << '\n';
    }

    return 0;
}