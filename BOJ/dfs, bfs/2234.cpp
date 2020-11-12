//2234
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 501
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { 0,-1,0,1 }, dy[] = { -1,0,1,0 };
int n, m;
int a[51][51], rn[51][51]; //맵, 방 번호 표시 맵
int c[2501]; //방 용량
bool chk[51][51], adj[2501][2501]; //중복 체크, 인접한지 체크
vi ADJ[2501]; //인접한 정보

bool OOB(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return true;
    return false;
}

void DFS(int x, int y, int num) {
    ++c[num];
    rn[x][y] = num;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (OOB(nx, ny)) continue;
        if (a[x][y] & (1 << i)) {
            
            //다른 영역이 이미 체크된 상태라면
            //표시한 방 번호로 현재 영역과 인접했음을 표시
            if (rn[nx][ny] && num != rn[nx][ny] && !adj[num][rn[nx][ny]]) {
                adj[num][rn[nx][ny]] = adj[rn[nx][ny]][num] = true;
                ADJ[num].push_back(rn[nx][ny]);
                ADJ[rn[nx][ny]].push_back(num);
            }
            continue;
        }
        if (chk[nx][ny]) continue;
        chk[nx][ny] = true;
        DFS(nx, ny, num);
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    int rooms = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (chk[i][j]) continue;
            chk[i][j] = true;
            DFS(i, j, ++rooms);
        }

    int large = 0, connected = 0;
    for (int i = 1; i <= rooms; ++i) {
        large = max(large, c[i]);
        for (auto& next : ADJ[i]) {
            connected = max(connected, c[i] + c[next]);
        }
    }

    printf("%d\n%d\n%d", rooms, large, connected);


    return 0;
}