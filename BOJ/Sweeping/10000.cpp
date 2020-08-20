//10000

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
#define MAX 400001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct cir {
    int l, r;
    bool left;

    cir(int l, int r, bool left) : l(l), r(r), left(left) {}
};

vector<cir> circle;
stack<cir> s;

bool cmp(const cir& a, const cir& b) {
    return a.l == b.l ? a.r > b.r : a.l < b.l;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x, r; cin >> x >> r;
        circle.push_back({ x - r, x + r, false });
    }
    sort(circle.begin(), circle.end(), cmp);

    ll ans = n + 1;
    bool left = false;
    int l = INF, r = -INF;
    for (int i = 0; i < n; i++) {
        //�� �ȿ� ���Ե� ��
        if (l <= circle[i].l && circle[i].r <= r) {
            if (l == circle[i].l) left = true;
            if (left && r == circle[i].r) ans++;
        }
        //���Ե��� ���� ��
        else {
            //�����ϴ� ���� ���� �� ���� ������
            while (!(l <= circle[i].l && circle[i].r <= r)) {
                if (s.empty()) {
                    l = INF; r = -INF; left = false;
                    break;
                }
                left = circle[i].l == r ? s.top().left : false; //���� ������ ���� ����
                l = s.top().l; r = s.top().r; s.pop();
            }

            //���� ���� ������ ���Ե� ��
            if (l <= circle[i].l && circle[i].r <= r) {
                if (l == circle[i].l) left = true;
                if (left && r == circle[i].r) ans++;
            }
        }
        s.push({ l, r, left });
        l = circle[i].l; r = circle[i].r; left = false;
    }

    cout << ans;

    return 0;
}