//2254

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
    int x, y, p, q, idx;
    Vertex(int x1, int y1, int idx=0) : x(x1), y(y1), p(1), q(0), idx(idx) {}
    
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

bool sameCCW(vector<Vertex> &tmp, Vertex& jail) {
    //마지막에서 처음으로 가는 경우도 체크하기 위함
    tmp.push_back(tmp[0]);

    int key = ccw(tmp[0], tmp[1], jail);
    for (int i = 0; i < tmp.size() - 1; i++) {
        if (ccw(tmp[i], tmp[i + 1], jail) != key) return false;
    }
    return true;
}

vector<Vertex> vertex;
bool chk[MAX];
ll ret;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    
    int n, jx, jy; cin >> n >> jx >> jy;
    Vertex jail = Vertex(jx, jy);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        vertex.push_back(Vertex(x, y, i));
    }
    while (1) {
        vector<Vertex> V;
        for (int i = 0; i < n; i++) {
            if (chk[i]) continue;
            V.push_back(vertex[i]);
        }

        if (V.size() < 3) break;

        //y좌표, x좌표가 작은 순으로 정렬
        sort(V.begin(), V.end());

        //기준점으로부터 상대 위치 계산
        for (int i = 1; i < V.size(); i++) {
            V[i].p = V[i].x - V[0].x;
            V[i].q = V[i].y - V[0].y;
        }

        //기준점을 제외하고 반시계 방향으로 정렬
        sort(V.begin()+1, V.end());

        //스택에는 V의 인덱스를 push
        stack<int> s;
        s.push(0); s.push(1);
        int next = 2;

        while (next < V.size()) {
            while (s.size() >= 2) {
                int first, second;
                second = s.top(); s.pop();
                first = s.top();

                //좌회전(CCW>0)이면 second를 push하고 진행
                //우회전(CCW<0)이면 현재 second를 버리고 진행
                if (ccw(V[first], V[second], V[next]) > 0) {
                    s.push(second);
                    break;
                }
            }
            s.push(next++);
        }

        vector<Vertex> tmp;
        while (!s.empty()) {
            chk[V[s.top()].idx] = true;
            tmp.push_back(V[s.top()]);
            s.pop();
        }

        if (sameCCW(tmp, jail)) ret++;
        else break;
    }

    cout << ret;

    return 0;
}