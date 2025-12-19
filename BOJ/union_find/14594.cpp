#include <bits/stdc++.h>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int INF = 987654321;

int n, m;
int parent[101];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void makeUnion(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    FASTIO;

    cin >> n >> m;

    for (int i=1; i<=n; i++) parent[i] = i;

    while (m--) {
        int x, y; cin >> x >> y;
        for (int i=x; i<y; i++) makeUnion(i, i+1);
    }

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (find(i) == i) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}