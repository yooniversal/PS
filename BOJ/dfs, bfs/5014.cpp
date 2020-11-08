//5014
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int F, S, G, U, D;
bool chk[1000001];

int BFS() {
    queue<ii> q;
    q.push({ S, 0 });
    chk[S] = true;
    while (!q.empty()) {
        int x = q.front().first, cnt = q.front().second; q.pop();
        if (x == G) return cnt;
        for (int to : {x + U, x - D}) {
            if (to < 1 || to > F) continue;
            if (chk[to]) continue;
            chk[to] = true;
            q.push({ to, cnt + 1 });
        }
    }
    return -1;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> F >> S >> G >> U >> D;
    int ret = BFS();
    if (ret != -1) cout << ret;
    else cout << "use the stairs";

    return 0;
}