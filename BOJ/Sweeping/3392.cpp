//3392

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
#define MAX 30005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll tree[MAX*4], cnt[MAX*4];

struct line {
    int x, lowy, highy;
    bool start;

    line(int x, int lowy, int highy, bool start) : x(x), lowy(lowy), highy(highy), start(start) {}
    bool operator<(const line& l) const { return x < l.x; }
};

void update(int node, int ns, int ne, int l, int r, ll val) {
    if (r < ns || ne < l) return;
    if (l <= ns && ne <= r) cnt[node] += val;
    else {
        int m = (ns + ne) / 2;
        update(node * 2, ns, m, l, r, val);
        update(node * 2 + 1, m+1, ne, l, r, val);
    }
    if (cnt[node]) tree[node] = ne - ns + 1;
    else
        if (ns == ne) tree[node] = 0;
        else tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<line> lines;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.push_back({ x1, y1, y2-1, true });
        lines.push_back({ x2, y1, y2-1, false });
    }

    //스위핑을 위해 x를 기준으로 오름차순 정렬
    sort(lines.begin(), lines.end());

    //첫 번째 사각형의 시작하는 변을 만났을 때
    line prev = lines[0];
    line cur = lines[0];
    update(1, 0, MAX-1, cur.lowy, cur.highy, 1);

    ll ret = 0;
    for (int i = 1; i < 2 * n; i++) {
        cur = lines[i];
        int dx = cur.x - prev.x;
        ret += dx * tree[1];

        if(cur.start) update(1, 0, MAX-1, cur.lowy, cur.highy, 1); //시작선
        else update(1, 0, MAX-1, cur.lowy, cur.highy, -1); //끝선
        prev = cur;
    }

    cout << ret;

    return 0;
}