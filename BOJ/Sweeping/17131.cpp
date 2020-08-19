//17131

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
#define MOD 1000000007
#define addX 200001
#define MAX 400001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct node {
    int x, y;

    node(int x, int y) : x(x), y(y) {}
    bool operator<(const node& n) const {
        return y == n.y ? x < n.x : y < n.y;
    }
};

vector<node> nodes;
ll tree[456789];

void update(int idx, ll diff) {
    for (int i = idx; i <= MAX; i += (i & -i)) {
        tree[i] += diff;
    }
}

ll sum(int idx) {
    ll ret = 0;
    for (int i = idx; i > 0; i -= (i & -i)) {
        ret += tree[i];
        ret %= MOD;
    }
    return ret;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        nodes.push_back({x, y});
        update(x + addX, 1); //현재 x에 있는 노드의 개수 업데이트
    }
    sort(nodes.begin(), nodes.end()); //y 오름차순 정렬

    ll ans = 0;
    int currentY = INF;
    for (int i = 0; i < n; i++) {
        if (nodes[i].y != currentY) {
            currentY = nodes[i].y;
            //같은 높이의 노드들 모두 트리에서 제거
            for (int j = i; nodes[j].y == currentY; j++) {
                update(nodes[j].x + addX, -1);
                if (j == n - 1) break;
            }
        }
        ll l = sum(nodes[i].x + addX - 1) % MOD;
        ll r = (sum(MAX) - sum(nodes[i].x + addX)) % MOD;
        ans += (l * r) % MOD;
        ans %= MOD;
    }

    cout << ans;

    return 0;
}