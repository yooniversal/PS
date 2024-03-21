#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MOD = 1000000007;

struct edge {
	int s, e, v;
	bool operator<(const edge& e) const {
		return v < e.v;
	}
};

int N, M;
int uni[100005];
vector<edge> E;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int find(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find(uni[a]);
}

void make_union(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa < pb) uni[b] = pa;
	else uni[a] = pb;
}

int main() {
    FASTIO();

    cin >> N >> M;
    while (M--) {
        int u, v, w; cin >> u >> v >> w;
        E.push_back({u, v, w});
    }
    sort(E.begin(), E.end());

    for (int i = 0; i < N; ++i) uni[i] = i;

    int ret = 0, max_w = 0;
    for (auto& edge : E) {
        int s = find(edge.s), e = find(edge.e), v = edge.v;
        if (s == e) continue; // 같은 그룹이면 패스
        make_union(s, e);
        ret += v;
        max_w = max(max_w, v);
    }

    cout << ret - max_w << '\n';

    return 0;
}