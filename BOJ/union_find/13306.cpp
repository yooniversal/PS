//13306
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 200005
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct Q {
    int mode, a, b;
};

int p[MAX], uni[MAX]; //바로 위 부모, 집합

int find(int a) {
    if (uni[a] == a) return a;
    return uni[a] = find(uni[a]);
}

void make_union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) uni[a] = pb;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    q += n - 1;

    for (int i = 1; i <= n; ++i) uni[i] = i;
    for (int i = 2; i <= n; ++i) cin >> p[i];
    
    stack<Q> S;
    for (int i = 0; i < q; ++i) {
        int mode; cin >> mode;
        if (mode == 0) {
            int x; cin >> x;
            S.push({ mode, x, 0 });
        }
        else {
            int a, b; cin >> a >> b;
            S.push({ mode, a, b });
        }
    }

    stack<string> ret;
    while (!S.empty()) {
        int mode = S.top().mode, a = S.top().a, b = S.top().b; S.pop();
        if (mode == 0) {
            make_union(a, p[a]);
        }
        else {
            if (find(a) == find(b)) ret.push("YES");
            else ret.push("NO");
        }
    }

    while (!ret.empty()) {
        cout << ret.top() << '\n';
        ret.pop();
    }

    return 0;
}