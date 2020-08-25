//10534

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
#define MAX 50001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct height {
    int x, y1, y2, num;
    bool operator<(height& r) { return x == r.x ? y1 < r.y1 : x < r.x; }
};

struct row {
    int y, x1, x2, num;
    bool operator<(row& r) { return y == r.y ? x1 < r.x1 : y < r.y; }
};

vector<height> H;
vector<row> R;
int uni[MAX];
ll area[MAX], ret;
bool chk[MAX];

int find(int a) {
    if (uni[a] == a) return a;
    return uni[a] = find(uni[a]);
}

void make_union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) {
        if (pa < pb) {
            uni[pb] = pa;
            if (!chk[pb]) {
                area[pa] += area[pb];
                ret = max(ret, area[pa]);
                chk[pb] = true;
            }
        }
        else {
            uni[pa] = pb;
            if (!chk[pa]) {
                area[pb] += area[pa];
                ret = max(ret, area[pb]);
                chk[pa] = true;
            }
        }
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    int n, id = 0; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, w, h; cin >> x >> y >> w >> h;
        H.push_back({ x, y, y + h, i });
        H.push_back({ x + w, y, y + h, i });
        R.push_back({ y, x, x + w, i });
        R.push_back({ y + h, x, x + w, i });
        area[i] = 1LL*w*h;
    }
    sort(H.begin(), H.end());
    sort(R.begin(), R.end());

    //initialize
    for (int i = 1; i <= n; i++) uni[i] = i;

    //옆으로 인접
    for (int i = 0; i < n*2-1; i++) {
        if (H[i].x == H[i+1].x) {
            if (H[i].y2 >= H[i+1].y1){
                int l = min(H[i].y1, H[i + 1].y1);
                int r = max(H[i].y2, H[i + 1].y2);
                H[i].y1 = H[i + 1].y1 = l;
                H[i].y2 = H[i + 1].y2 = r;
                make_union(H[i].num, H[i+1].num);
                
            }
        }
    }

    //위아래로 인접
    for (int i = 0; i < n*2-1; i++) {
        if (R[i].y == R[i+1].y) {
            if (R[i].x2 >= R[i+1].x1) {
                int l = min(R[i].x1, R[i + 1].x1);
                int r = max(R[i].x2, R[i + 1].x2);
                R[i].x1 = R[i + 1].x1 = l;
                R[i].x2 = R[i + 1].x2 = r;
                make_union(R[i].num, R[i+1].num);
            }
        }
    }   

    for (int i = 1; i <= n; i++) {
        ret = max(ret, area[i]);
    }

    cout << ret;

    return 0;
}