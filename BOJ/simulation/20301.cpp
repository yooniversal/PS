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

bool removed[5005];

int main() {
    FASTIO;

    int N, K, M; cin >> N >> K >> M;

    deque<int> dq;
    for (int i=1; i<=N; i++) dq.push_back(i);

    int dir = 1;
    int removed = 0;

    while (!dq.empty()) {
        for (int i=0; i<K-1; i++) {
            if (dir == 1) {
                dq.push_back(dq.front());
                dq.pop_front();
            } else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

        if (dir == 1) {
            cout << dq.front() << '\n';
            dq.pop_front();
        } else {
            cout << dq.back() << '\n';
            dq.pop_back();
        }

        removed++;
        if (removed % M == 0) {
            dir *= -1;
        }
    }

    return 0;
}