//2665
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n;
vector<string> MAP;
int dist[MAX];
bool chk[MAX];
vii a[MAX];

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<ii> pq; //가까운 순서대로 처리하기 위함
    pq.push({ 0, start });
    while (!pq.empty()) {
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        if (chk[cur]) continue;
        chk[cur] = true;

        //최단거리가 아님
        if (dist[cur] < distance) continue;
        for (auto& next : a[cur]) {
            int nextDist = distance + next.second;
            if (nextDist < dist[next.first]) {
                dist[next.first] = nextDist;
                pq.push({ -nextDist, next.first });
            }
        }
    }
}

bool OOB(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return true;
    return false;
}

int convert(int x, int y) {
    return x * n + y;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    fill(dist, dist + MAX, INF);
    cin >> n;
    MAP.resize(n);
    for (int i = 0; i < n; ++i) cin >> MAP[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int dir = 0; dir < 4; ++dir) {
                int nx = i + dx[dir], ny = j + dy[dir];
                if (OOB(nx, ny)) continue;
                int w = 0;
                if (MAP[nx][ny] == '0') ++w;
                a[convert(i, j)].push_back({ convert(nx, ny), w });
            }
        }
    }

    dijkstra(0);

    cout << dist[convert(n - 1, n - 1)];

    return 0;
}