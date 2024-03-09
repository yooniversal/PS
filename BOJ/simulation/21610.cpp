#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 987654321;
typedef pair<int, int> ii;

int N, M;
int a[51][51];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

vector<ii> clouds;
map<ii, bool> chk;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int OOB(int x, int y) {
    return x<0 || x>=N || y<0 || y>=N;
}

void move(ii& cur, int d, int s) {
    int x = cur.first, y = cur.second;

    x += dx[d] * s;
    x %= N;
    if (x < 0) x += N;

    y += dy[d] * s;
    y %= N;
    if (y < 0) y += N;

    cur.first = x;
    cur.second = y;
}

int main() {
    FASTIO();
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=0; i<M; i++) {
        int d, s; cin >> d >> s;
        d--;

        if (i == 0) {
            ii init_xy[] = {
                {N-1, 0},
                {N-1, 1},
                {N-2, 0},
                {N-2, 1}
            };
            for (auto& xy : init_xy) {
                clouds.push_back(xy);
                chk[xy] = true;
            }
        }
        
        // 구름 이동
        for (auto& cloud : clouds) chk[{cloud.first, cloud.second}] = false;
        for (auto& cloud : clouds) {
            chk[{cloud.first, cloud.second}] = false;
            move(cloud, d, s);
        }
        for (auto& cloud : clouds) chk[{cloud.first, cloud.second}] = true;

        // 물 주기
        for (auto& cloud : clouds) {
            a[cloud.first][cloud.second]++;
        }

        // 물 복사
        int diag_dir[] = {1, 3, 5, 7};
        for (auto& cloud : clouds) {
            for (auto& d : diag_dir) {
                int x = cloud.first + dx[d];
                int y = cloud.second + dy[d];
                if (OOB(x, y)) continue;
                if (a[x][y] <= 0) continue;
                a[cloud.first][cloud.second]++;
            }
        }

        // 구름 생성
        clouds.clear();
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (chk[{i, j}]) continue;
                if (a[i][j] >= 2) {
                    a[i][j] -= 2;
                    clouds.push_back({i, j});
                }
            }
        }

        // 구름 생성 위치 체크
        chk.clear();
        for (auto& cloud : clouds) {
            chk[{cloud.first, cloud.second}] = true;
        }
    }

    int ret = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            ret += a[i][j];
        }
    }

    cout << ret << '\n';

    return 0;
}