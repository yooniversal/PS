//4225

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
    Vertex(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
    bool operator<(const Vertex& a) const {
        if (q * a.p != p * a.q)
            return q * a.p < p* a.q;
        if (y != a.y) return y < a.y;
        return x < a.x;
    }
    Vertex operator-(const Vertex& a) const {
        return Vertex(x - a.x, y - a.y);
    }
    bool operator==(const Vertex& a) const {
        return x == a.x && y == a.y;
    }
};

ll ccw(const Vertex& a, const Vertex& b, const Vertex& c) {
    int x1 = a.x, x2 = b.x, x3 = c.x;
    int y1 = a.y, y2 = b.y, y3 = c.y;
    ll temp = 1LL * x1 * y2 + 1LL * x2 * y3 + 1LL * x3 * y1;
    temp = temp - 1LL * y1 * x2 - 1LL * y2 * x3 - 1LL * y3 * x1;
    return temp;
}

vector<Vertex> convexHull(vector<Vertex>& vertex) {
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

double dist(const Vertex& a, const Vertex& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double solve(Vertex& a, Vertex& b1, Vertex& b2) {
    return abs(abs(ccw(a, b1, b2)) / abs(dist(b1, b2)));
}


int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    //ios_base::sync_with_stdio(false);

    int CASE = 1;
    while (1) {
        int n; scanf("%d", &n);
        if (n == 0) return 0;
        vector<Vertex> input;
        for (int i = 0; i < n; i++) {
            int x, y; scanf("%d %d", &x, &y);
            input.push_back(Vertex(x, y));
        }

        vector<Vertex> CH = convexHull(input);

        double ret = 1e10;
        for (int i = 0; i < CH.size(); i++) {
            double tmp = 0.0;
            for (int j = 0; j < CH.size(); j++) {
                tmp = max(tmp, solve(CH[j], CH[i], CH[(i+1)%CH.size()]));
            }
            ret = min(ret, tmp);
        }

        printf("Case %d: %.2lf\n", CASE++, ceil(ret*100)/100);
    }

    return 0;
}