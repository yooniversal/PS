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

const int INF = 987654321;
const int MOD = 1000000007;

bool solve(string& s, int n, int& pos) {
    string v = to_string(n);
    for (int i=0; i < v.size() && pos < s.size(); i++) {
        if (v[i] == s[pos]) pos++;
    }

    return pos >= s.size();
}

int main() {
    FASTIO;

    string s; cin >> s;

    int ret = 1;
    int pos = 0;

    while (!solve(s, ret, pos)) {
        ret++;
    }

    cout << ret << '\n';

    return 0;
}