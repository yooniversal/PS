//1310

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 987654321
#define MAX 1001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct Vertex {
    ll x, y, p, q;
    Vertex(int x1=0, int y1=0) : x(x1), y(y1), p(1), q(0) {}
    bool operator<(const Vertex& a) const {
        if (q * a.p != p * a.q)
            return q * a.p < p * a.q;
        if (y != a.y) return y < a.y;
        return x < a.x;
    }
    Vertex operator-(const Vertex& a) const {
        return Vertex(x - a.x, y - a.y);
    }
};

ll ccw(const Vertex& a, const Vertex& b, const Vertex& c) {
    int x1 = a.x, x2 = b.x, x3 = c.x;
    int y1 = a.y, y2 = b.y, y3 = c.y;
    ll temp = 1LL * x1 * y2 + 1LL * x2 * y3 + 1LL * x3 * y1;
    temp = temp - 1LL * y1 * x2 - 1LL * y2 * x3 - 1LL * y3 * x1;
    return temp;
}

vector<Vertex> convexHull(vector<Vertex> &vertex) {
    if (vertex.size() < 3) return vertex;

    sort(vertex.begin(), vertex.end());

    for (int i = 1; i < vertex.size(); i++) {
        vertex[i].p = vertex[i].x - vertex[0].x;
        vertex[i].q = vertex[i].y - vertex[0].y;
    }

    sort(vertex.begin() + 1, vertex.end());

    stack<int> s;
    s.push(0); s.push(1);
    int next = 2;

    while (next < vertex.size()) {
        while (s.size() >= 2) {
            int first, second;
            second = s.top(); s.pop();
            first = s.top();

            if (ccw(vertex[first], vertex[second], vertex[next]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(next++);
    }
    if (s.size() < 3) return vertex;

    vector<Vertex> tmp;
    while (!s.empty()) {
        tmp.push_back(vertex[s.top()]);
        s.pop();
    }
    reverse(tmp.begin(), tmp.end());

    return tmp;
}

ll dist(const Vertex& a, const Vertex& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<Vertex> input;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        input.push_back(Vertex(x, y));
    }

    vector<Vertex> CH = convexHull(input);

    ll ret = 0;
    const int SIZE = CH.size();
    int C = 1;
    for (int A = 0; A < SIZE; A++) {
        int B = (A + 1) % SIZE;
        while (1) {
            int D = (C + 1) % SIZE;

            Vertex zero;
            Vertex AB = CH[B] - CH[A];
            Vertex CD = CH[D] - CH[C];

            if (ccw(zero, AB, CD) > 0)
                C = D;
            else
                break;
        }

        ret = max(ret, dist(CH[A], CH[C]));
    }
    ret = max(ret, dist(CH[0], CH[SIZE - 1]));

    cout << ret;

    return 0;
}