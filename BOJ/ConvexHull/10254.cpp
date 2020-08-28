//10254

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
#define MAX 200001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct Vertex {
    int x, y, p, q;
    Vertex(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
    bool operator<(const Vertex& a) const {
        //�ݽð� �������� ����
        if (1LL * q * a.p != 1LL * p * a.q)
            return 1LL * q * a.p < 1LL * p * a.q;
        //y, x�� ���� ������ ����
        if (y != a.y) return y < a.y;
        return x < a.x;
    }
    Vertex operator-(const Vertex& a) const {
        return Vertex(x - a.x, y - a.y);
    }
};

Vertex vertex[MAX];

ll ccw(const Vertex& a, const Vertex& b, const Vertex& c) {
    int x1 = a.x, x2 = b.x, x3 = c.x;
    int y1 = a.y, y2 = b.y, y3 = c.y;
    ll temp = 1LL * x1 * y2 + 1LL * x2 * y3 + 1LL * x3 * y1;
    temp = temp - 1LL * y1 * x2 - 1LL * y2 * x3 - 1LL * y3 * x1;
    return temp;
}

ll dist(const Vertex& a, const Vertex& b) {
    return 1LL* (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            vertex[i] = Vertex(x, y);
        }

        //������ vertex�� p, q�� �������� �ʾ����Ƿ�
        //y��ǥ, x��ǥ�� ���� ������ ����
        sort(vertex, vertex + n);

        //���������κ��� ��� ��ġ ���
        //p, q ����
        for (int i = 1; i < n; i++) {
            vertex[i].p = vertex[i].x - vertex[0].x;
            vertex[i].q = vertex[i].y - vertex[0].y;
        }

        //�������� �����ϰ� �ݽð� �������� ����
        sort(vertex + 1, vertex + n);

        //���ÿ��� vertex�� �ε����� push
        stack<int> s;
        s.push(0); s.push(1);
        int next = 2;

        while (next < n) {
            while (s.size() >= 2) {
                int first, second;
                second = s.top(); s.pop();
                first = s.top();

                //��ȸ��(CCW>0)�̸� second�� push�ϰ� ����
                //��ȸ��(CCW<0)�̸� ���� second�� ������ ����
                if (ccw(vertex[first], vertex[second], vertex[next]) > 0) {
                    s.push(second);
                    break;
                }
            }
            s.push(next++);
        }

        vector<Vertex> convexhull(s.size());
        int id = s.size() - 1; //���� ��ġ�� ����
        while (!s.empty()) {
            convexhull[id--] = vertex[s.top()];
            s.pop();
        }


        ll ret = 0;
        pair<Vertex, Vertex> xy;
        const int SIZE = convexhull.size();
        int C = 1;
        
        for (int A = 0; A < SIZE; A++) {
            int B = (A + 1) % SIZE;
            while (1) {
                int D = (C + 1) % SIZE;

                Vertex zero;
                Vertex AB = convexhull[B] - convexhull[A];
                Vertex CD = convexhull[D] - convexhull[C];

                if (ccw(zero, AB, CD) > 0)
                    C = D;
                else
                    break;
            }

            if (ret < dist(convexhull[A], convexhull[C])) {
                ret = dist(convexhull[A], convexhull[C]);
                xy = { convexhull[A], convexhull[C] };
            }
        }

        cout << xy.first.x << " " << xy.first.y << " " << xy.second.x << " " << xy.second.y << '\n';
    }

    return 0;
}