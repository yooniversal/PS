//9240

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
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct Vertex {
    int x, y, p, q;
    Vertex(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};

Vertex vertex[MAX];

ll ccw(const Vertex& a, const Vertex& b, const Vertex& c) {
    int x1 = a.x, x2 = b.x, x3 = c.x;
    int y1 = a.y, y2 = b.y, y3 = c.y;
    ll temp = 1LL * x1 * y2 + 1LL * x2 * y3 + 1LL * x3 * y1;
    temp = temp - 1LL * y1 * x2 - 1LL * y2 * x3 - 1LL * y3 * x1;
    return temp;
}

bool cmp(const Vertex& a, const Vertex& b) {
    //반시계 방향으로 정렬
    if (1LL * a.q * b.p != 1LL * a.p * b.q)
        return 1LL * a.q * b.p < 1LL * a.p * b.q;
    //y, x를 작은 순으로 정렬
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

ll dist(const Vertex& a, const Vertex& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        vertex[i] = Vertex(x, y);
    }

    //아직은 vertex의 p, q가 설정되지 않았으므로
    //y좌표, x좌표가 작은 순으로 정렬
    sort(vertex, vertex + n, cmp);

    //기준점으로부터 상대 위치 계산
    //p, q 설정
    for (int i = 1; i < n; i++) {
        vertex[i].p = vertex[i].x - vertex[0].x;
        vertex[i].q = vertex[i].y - vertex[0].y;
    }

    //기준점을 제외하고 반시계 방향으로 정렬
    sort(vertex + 1, vertex + n, cmp);

    //스택에는 vertex의 인덱스를 push
    stack<int> s;
    s.push(0); s.push(1);
    int next = 2;

    while (next < n) {
        while (s.size() >= 2) {
            int first, second;
            second = s.top(); s.pop();
            first = s.top();

            //좌회전(CCW>0)이면 second를 push하고 진행
            //우회전(CCW<0)이면 현재 second를 버리고 진행
            if (ccw(vertex[first], vertex[second], vertex[next]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(next++);
    }

    vector<Vertex> some(s.size());
    int id = s.size() - 1; //원래 위치로 복구
    while (!s.empty()) {
        some[id--] = vertex[s.top()];
        s.pop();
    }
    
    
    ll ret = 0;
    for (int i = 0; i < some.size() - 1; i++) {
        for (int j = i + 1; j < some.size(); j++) {
            ret = max(ret, dist(some[i], some[j]));
        }
    }

    printf("%.6lf", sqrt(ret));

    return 0;
}