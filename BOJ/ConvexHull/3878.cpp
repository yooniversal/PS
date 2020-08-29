//3878
//못풀었음..!

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
    int x, y, p, q;
    Vertex(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}

    Vertex operator-(const Vertex& a) const {
        return Vertex(x - a.x, y - a.y);
    }

    bool operator<(const Vertex& b) {
        if (1LL * q * b.p != 1LL * p * b.q)
            return 1LL * q * b.p < 1LL * p * b.q;
        if (y != b.y) return y < b.y;
        return x < b.x;
    }
};

int ccw(const Vertex& a, const Vertex& b, const Vertex& c) {
    int x1 = a.x, x2 = b.x, x3 = c.x;
    int y1 = a.y, y2 = b.y, y3 = c.y;
    ll temp = 1LL * x1 * y2 + 1LL * x2 * y3 + 1LL * x3 * y1;
    temp = temp - 1LL * y1 * x2 - 1LL * y2 * x3 - 1LL * y3 * x1;
    if (temp < 0) return -1;
    else if (temp > 0) return 1;
    return 0;
}

//MAKE CONVEX HULL
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

    vector<Vertex> tmp;
    while (!s.empty()) {
        tmp.push_back(vertex[s.top()]);
        s.pop();
    }

    return tmp;
}

bool isCross(Vertex& a1, Vertex& a2, Vertex& b1, Vertex& b2) {
    if (ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 && ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0) {
        if ((a1.x < b1.x && a1.x < b2.x) || (a2.x < b1.x && a2.x < b2.x)) return false;
        if ((a1.y < b1.y && a1.y < b2.y) || (a2.y < b1.y && a2.y < b2.y)) return false;
        return true;
    }
    return false;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        vector<Vertex> black, white;
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            black.push_back(Vertex(x, y));
        }
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            white.push_back(Vertex(x, y));
        }

        vector<Vertex> B = convexHull(black);
        vector<Vertex> W = convexHull(white);

        if (B.size() == 1 || W.size() == 1) {
            //검은점, 흰점의 볼록 껍질 모두 속한 점이 1개일 때
            if (B.size() == 1 && W.size() == 1) cout << "YES" << '\n';
            //검은점의 볼록 껍질에 속한게 1개일 때
            else if (B.size() == 1) {
                int flag = ccw(B[0], W[0], W[1]);
                if (flag == 0) {
                    if ((B[0].x < W[0].x && B[0].x < W[1].x) || (B[0].x > W[0].x && B[0].x > W[1].x)) {
                        cout << "NO" << '\n';
                        continue;
                    }
                    if ((B[0].y < W[0].y && B[0].y < W[1].y) || (B[0].y > W[0].y && B[0].y > W[1].y)) {
                        cout << "NO" << '\n';
                        continue;
                    }
                    cout << "YES" << '\n';
                }
                else {
                    for (int i = 0; i < W.size() - 1; i++) {
                        if (flag != ccw(B[0], W[i], W[i + 1])) {
                            cout << "NO" << '\n';
                            continue;
                        }
                    }
                    cout << "YES" << '\n';
                }
            }
            //흰점의 볼록 껍질에 속한게 1개일 때
            else {
                int flag = ccw(W[0], B[0], B[1]);
                if (flag == 0) {
                    if ((W[0].x < B[0].x && W[0].x < B[1].x) || (W[0].x > B[0].x && W[0].x > B[1].x)) {
                        cout << "NO" << '\n';
                        continue;
                    }
                    if ((W[0].y < B[0].y && W[0].y < B[1].y) || (W[0].y > B[0].y && W[0].y > B[1].y)) {
                        cout << "NO" << '\n';
                        continue;
                    }
                    cout << "YES" << '\n';
                }
                else {
                    for (int i = 0; i < B.size() - 1; i++) {
                        if (flag != ccw(W[0], B[i], B[i + 1])) {
                            cout << "NO" << '\n';
                            continue;
                        }
                    }
                    cout << "YES" << '\n';
                }
            }   
        }
        else {
            bool ret = true;
            for (int i = 0; i < B.size() - 1; i++) {
                for (int j = 0; j < W.size() - 1; j++) {
                    if (isCross(B[i], B[i + 1], W[i], W[i + 1])) {
                        ret = false;
                        i = B.size(); j = W.size();
                    }
                }
            }
            if (!ret) {
                cout << "NO" << '\n';
                continue;
            }

            ret = true;
            for (int i = 0; i < B.size() - 1; i++) {
                for (int j = 0; j < W.size(); j++) {
                    if (ccw(B[i], B[i + 1], W[j]) <= 0) {
                        ret = false;
                        i = B.size(); j = W.size() + 1;
                    }
                }
            }
            if (!ret) {
                cout << "NO" << '\n';
                continue;
            }

            ret = true;
            for (int i = 0; i < W.size() - 1; i++) {
                for (int j = 0; j < B.size(); j++) {
                    if (ccw(W[i], W[i + 1], B[j]) <= 0) {
                        ret = false;
                        i = B.size(); j = W.size() + 1;
                    }
                }
            }
            if (!ret) {
                cout << "NO" << '\n';
                continue;
            }

            cout << "YES" << '\n';
        }
    }

    return 0;
}