//7420

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
    Vertex(int x1, int y1, int idx = 0) : x(x1), y(y1), p(1), q(0), idx(idx) {}

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

bool sameCCW(vector<Vertex>& tmp, Vertex& jail) {
    //���������� ó������ ���� ��쵵 üũ�ϱ� ����
    tmp.push_back(tmp[0]);

    int key = ccw(tmp[0], tmp[1], jail);
    for (int i = 0; i < tmp.size() - 1; i++) {
        if (ccw(tmp[i], tmp[i + 1], jail) != key) return false;
    }
    return true;
}

double dist(Vertex& a, Vertex& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

vector<Vertex> vertex;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    //ios_base::sync_with_stdio(false);

    int n, l; scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        vertex.push_back(Vertex(x, y, i));
    }

    //y��ǥ, x��ǥ�� ���� ������ ����
    sort(vertex.begin(), vertex.end());

    //���������κ��� ��� ��ġ ���
    for (int i = 1; i < vertex.size(); i++) {
        vertex[i].p = vertex[i].x - vertex[0].x;
        vertex[i].q = vertex[i].y - vertex[0].y;
    }

    //�������� �����ϰ� �ݽð� �������� ����
    sort(vertex.begin() + 1, vertex.end());

    //���ÿ��� V�� �ε����� push
    stack<int> s;
    s.push(0); s.push(1);
    int next = 2;

    while (next < vertex.size()) {
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

    vector<Vertex> tmp;
    while (!s.empty()) {
        tmp.push_back(vertex[s.top()]);
        s.pop();
    }

    double ret = 0;
    tmp.push_back(tmp[0]);
    for (int i = 0; i < tmp.size() - 1; i++) {
        ret += dist(tmp[i], tmp[i + 1]);
    }
    ret += 3.141592 * 2 * l;

    printf("%.0lf", ret);

    return 0;
}