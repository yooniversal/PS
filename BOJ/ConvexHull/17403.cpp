//17403

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
    int x, y, p, q, floor, idx;
    Vertex(int x1, int y1, int idx=0) : x(x1), y(y1), p(1), q(0), floor(0), idx(idx) {}
    bool operator<(const Vertex& a) const {
        if (1LL * q * a.p != 1LL * p * a.q)
            return 1LL * q * a.p < 1LL * p * a.q;
        if (y != a.y) return y < a.y;
        return x < a.x;
    }
    Vertex operator-(const Vertex& a) const {
        return Vertex(x - a.x, y - a.y);
    }
};

bool chk[MAX];
int level = 1;
vector<Vertex> input;

ll ccw(const Vertex& a, const Vertex& b, const Vertex& c) {
    int x1 = a.x, x2 = b.x, x3 = c.x;
    int y1 = a.y, y2 = b.y, y3 = c.y;
    ll temp = 1LL * x1 * y2 + 1LL * x2 * y3 + 1LL * x3 * y1;
    temp = temp - 1LL * y1 * x2 - 1LL * y2 * x3 - 1LL * y3 * x1;
    return temp;
}

void convexHull() {
    while (1) {
        vector<Vertex> vertex;
        for (int i = 0; i < input.size(); i++) {
            if (chk[i]) continue;
            vertex.push_back(input[i]);
        }

        if (vertex.size() < 3) return;

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
        if (s.size() < 3) return;

        while (!s.empty()) {
            chk[vertex[s.top()].idx] = true;
            input[vertex[s.top()].idx].floor = level;
            s.pop();
        }

        level++;
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        input.push_back(Vertex(x, y, i));
    }

    convexHull();

    for (int i = 0; i < n; i++) {
        cout << input[i].floor << " ";
    }

    return 0;
}