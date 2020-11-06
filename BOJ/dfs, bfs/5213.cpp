//5213
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 501
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
    int tile, n;
    P(int a, int b) : tile(a), n(b) {}
    P() { P(0, 0); }
};

int dx[] = { 0,0,1,-1 }, dy[] = { -1,1,0,0 };
int n, target;
int PREV[MAX * MAX];
bool chk[MAX * MAX];
P m[MAX][MAX * 2];

bool OOB(int x, int y) {
    if (x % 2) {
        if (x<1 || x>n || y < 1 || y>2 * n) return true;
        return false;
    }
    else {
        if (x<1 || x>n || y <= 1 || y >= 2 * n) return true;
        return false;
    }
}

void BFS() {
    queue<ii> q;
    q.push({ 1, 1 });
    chk[1] = true;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        target = max(target, m[x][y].tile);
        //같은 타일로 이동하는 경우 -> 경로 길이 노카운트
        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (m[x][y].tile != m[nx][ny].tile) continue;

            //다른 타일로 이동
            for (int j = 0; j < 4; ++j) {
                int jx = nx + dx[j], jy = ny + dy[j];
                if (OOB(jx, jy)) continue;
                if (PREV[m[jx][jy].tile]) continue;
                if (m[nx][ny].tile == m[jx][jy].tile) continue;
                if (m[nx][ny].n != m[jx][jy].n) continue;
                PREV[m[jx][jy].tile] = m[nx][ny].tile;
                q.push({ jx, jy });
            }
        }

        //다른 타일로 이동
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny)) continue;
            if (PREV[m[nx][ny].tile]) continue;
            if (m[x][y].tile == m[nx][ny].tile) continue;
            if (m[x][y].n != m[nx][ny].n) continue;
            PREV[m[nx][ny].tile] = m[x][y].tile;
            q.push({ nx, ny });
        }
    }
}

void traversal() {
    stack<int> ret;
    for (int i = target; i != 1; i = PREV[i]) {
        ret.push(i);
    }
    ret.push(1);
    cout << ret.size() << '\n';
    while (!ret.empty()) {
        cout << ret.top() << ' ';
        ret.pop();
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int row = 1, col = 1; //행이 홀수면 N개, 짝수면 N-1개
    for (int i = 1; i <= n * n - n/2; ++i) {
        int a, b; cin >> a >> b;
        if (row % 2) {
            m[row][col++] = P(i, a);
            m[row][col++] = P(i, b);
            if (col > 2 * n) {
                col = 2;
                ++row;
            }
        }
        else {
            m[row][col++] = P(i, a);
            m[row][col++] = P(i, b);
            if (col >= 2 * n) {
                col = 1;
                ++row;
            }
        }
    }
    
    BFS();
    traversal();

    return 0;
}