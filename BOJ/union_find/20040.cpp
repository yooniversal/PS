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

int N, M;
int uni[500005];
vector<pair<int, int>> input;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int find_parent(int a) {
    if (uni[a] == a) return a;
    return uni[a] = find_parent(uni[a]);
}

void make_union(int a, int b) {
    int fa = find_parent(a), fb = find_parent(b);
    if (fa == fb) return;
    uni[fb] = fa;
}

int main() {
    FASTIO();

    for (int i=0; i<500005; i++) {
        uni[i] = i;
    }

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int u, v; cin >> u >> v;
        input.push_back({u, v});
    }

    bool flag = true;
    for (int i=0; i<M; i++) {
        pair<int, int> cur = input[i];
        int fp = find_parent(cur.first);
        int sp = find_parent(cur.second);
        if (fp == sp) {
            cout << i+1 << '\n';
            flag = false;
            break;
        }
        
        make_union(cur.first, cur.second);
    }

    if (flag) cout << 0 << '\n';

    return 0;
}