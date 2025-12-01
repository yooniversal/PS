#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

struct S {
    int x, y;
    bool operator<(const S& s) const {
        if (x != s.x) return x < s.x;
        return y > s.y;
    }   
};

int h[370];
bool selected[370][1005];

int searchHeight(S& s) {
    for (int height=0; height<=1000; height++) {
        bool flag = true;
        for (int i=s.x; i<=s.y; i++) {
            if (selected[i][height]) {
                flag = false;
                break;
            }
        }

        if (flag) return height + 1;
    }

    return -1;
}

void insert(S& s) {
    int targetHeight = searchHeight(s);
    for (int i=s.x; i<=s.y; i++) {
        h[i] = max(h[i], targetHeight);
        selected[i][targetHeight-1] = true;
    }
}

int main() {
    FASTIO;

    int n; cin >> n;
    vector<S> a;
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());

    for (auto& s : a) insert(s);

    int ret = 0;

    int prev = -1, maxH = 0;
    for (int x=1; x<=365; x++) {
        if (prev == -1 && h[x] > 0) {
            prev = x;
            maxH = max(maxH, h[x]);
        } else if (h[x] > 0) {
            maxH = max(maxH, h[x]);
        } else {
            ret += (x - prev) * maxH;
            prev = -1;
            maxH = 0;
        }
    }

    if (prev != -1 && maxH != 0) ret += (366 - prev) * maxH;

    cout << ret << '\n';

    return 0;
}