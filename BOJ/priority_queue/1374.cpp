#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

struct C {
    int number;
    int startTime;
    int endTime;
    C(int a, int b, int c): number(a), startTime(b), endTime(c) {}

    bool operator<(const C& c) const {
        if (startTime != c.startTime) return startTime < c.startTime;
        return endTime < c.endTime;
    }
};

struct Compare {
    bool operator()(const C& a, const C& b) const {
        return a.endTime > b.endTime;
    }
};

int main() {
    FASTIO;

    int n; cin >> n;
    vector<C> classes;
    for (int i=0; i<n; i++) {
        int a, b, c; cin >> a >> b >> c;
        classes.push_back(C(a, b, c));
    }
    sort(classes.begin(), classes.end());

    int ret = 0;
    priority_queue<C, vector<C>, Compare> pq;
    for (auto& c : classes) {
        if (pq.empty()) {
            pq.push(c);
        } else {
            if (c.startTime < pq.top().endTime) {
                pq.push(c);
            } else {
                while (!pq.empty() && c.startTime >= pq.top().endTime) pq.pop();
                pq.push(c);
            }
        }

        ret = max(ret, (int)pq.size());
    }

    cout << ret << '\n';

    return 0;
}