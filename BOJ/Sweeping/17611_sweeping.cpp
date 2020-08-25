//17611

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
#define MAX 500001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct height {
    int y, start;
    bool operator<(height& h) { return y == h.y ? start < h.start : y < h.y; }
};

struct row {
    int x, start;
    bool operator<(row& r) { return x == r.x ? start < r.start : x < r.x; }
};

vector<height> H;
vector<row> R;

void process(int x1, int x2, int y1, int y2) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    //작은값에는 1을, 큰값에는 -1 넣기
    //시작점, 끝점 구별 및 정답 계산에 도움을 줌
    if (x1 != x2) {
        R.push_back({ x1, 1 });
        R.push_back({ x2, -1 });
    }
    else {
        H.push_back({ y1, 1 });
        H.push_back({ y2, -1 });
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int sx, sy; cin >> sx >> sy;
    int cx = sx, cy = sy; //compare x, y
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        process(cx, x, cy, y);
        cx = x; cy = y;
    }
    //시작점과 끝점은 이어져야 함
    process(cx, sx, cy, sy);
    
    sort(R.begin(), R.end());
    sort(H.begin(), H.end());

    int ret=0, tmp=0;
    for (int i = 0; i < R.size(); i++) {
        tmp += R[i].start;
        ret = max(ret, tmp);
    }
    for (int i = 0; i < H.size(); i++) {
        tmp += H[i].start;
        ret = max(ret, tmp);
    }

    cout << ret;

    return 0;
}