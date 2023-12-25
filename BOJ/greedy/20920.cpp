#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

struct S {
    int cnt;
    string s;

    S(int a, string b): cnt(a), s(b) {}
    bool operator<(S& nxt) {
        if (cnt != nxt.cnt) return cnt > nxt.cnt;
        if (s.size() != nxt.s.size()) return s.size() > nxt.s.size();
        return s < nxt.s;
    }  
};

map<string, bool> chk;
map<string, int> idx;
vector<S> a;

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    while (n--) {
        string s; cin >> s;
        if (s.size() < m) continue;

        if (chk[s]) {
            a[idx[s]].cnt++;
            continue;
        }

        a.push_back(S(1, s));
        chk[s] = true;
        idx[s] = a.size()-1;
    }

    sort(a.begin(), a.end());

    for (auto& aa : a) {
        cout << aa.s << '\n';
    }

    return 0;
}