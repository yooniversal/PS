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

int main() {
    FASTIO;

    int n; cin >> n;
    deque<int> dq;

    while (n--) {
        int q; cin >> q;

        if (q == 1) {
            int x; cin >> x;
            dq.push_front(x);
        } else if (q == 2) {
            int x; cin >> x;
            dq.push_back(x);
        } else if (q == 3) {
            if (dq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (q == 4) {
            if (dq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (q == 5) {
            cout << dq.size() << '\n';
        } else if (q == 6) {
            cout << (dq.empty() ? 1 : 0) << '\n';
        } else if (q == 7) {
            if (dq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << dq.front() << '\n';
            }
        } else {
            if (dq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << dq.back() << '\n';
            }
        }
    }

    return 0;
}