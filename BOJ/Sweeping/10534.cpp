//10534
//non-complete

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
vi utl[MAX];
ll area[MAX];

int find_union(int a) {
    if (uni[a] == a) return a;
    return uni[a] = find_union(uni[a]);
}

//line -> union -> line
int Utl_H(int i) {
    int p = find_union(H[i].num);
    int x = H[i].x;
    if (H[utl[p][0]].x == x) return utl[p][0];
    else if (H[utl[p][1]].x == x) return utl[p][1];
    else return i;
}

int Utl_R(int i) {
    int p = find_union(R[i].num);
    int y = R[i].y;
    if (R[utl[p][0]].y == y) return utl[p][0];
    else if (R[utl[p][1]].y == y) return utl[p][1];
    else return i;
}

void make_union_H(int a, int b) {
    int pa = find_union(H[a].num), pb = find_union(H[b].num);
    if (pa != pb) {
        int l = min(H[b].y1, min(H[a].y1, min(H[Utl_H(a)].y1, H[Utl_H(b)].y1)));
        int r = max(H[b].y2, max(H[a].y2, max(H[Utl_H(a)].y2, H[Utl_H(b)].y2)));
        H[Utl_H(a)].y1 = H[Utl_H(b)].y1 = H[a].y1 = H[b].y1 = l;
        H[Utl_H(a)].y2 = H[Utl_H(b)].y2 = H[a].y2 = H[b].y2 = r;
        if (pa < pb)  uni[H[b].num] = pa;
        else uni[H[a].num] = pb;
    }
}

void make_union_R(int a, int b) {
    int pa = find_union(R[a].num), pb = find_union(R[b].num);
    if (pa != pb) {
        int l = min(R[b].x1, min(R[a].x1, min(R[Utl_R(a)].x1, R[Utl_R(b)].x1)));
        int r = max(R[b].x2, max(R[a].x2, max(R[Utl_R(a)].x2, R[Utl_R(b)].x2)));
        R[Utl_R(a)].x1 = R[Utl_R(b)].x1 = R[a].x1 = R[b].x1 = l;
        R[Utl_R(a)].x2 = R[Utl_R(b)].x2 = R[a].x2 = R[b].x2 = r;
        if (pa < pb) uni[R[b].num] = pa;
        else uni[R[a].num] = pb;
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

    //for (int i = 0; i < 2 * n; i++) printf("H[%d].num:%d x:%d\n", i, H[i].num, H[i].x);

    //initialize
    for (int i = 1; i <= n; i++) uni[i] = i;
    for (int i = 0; i < 2 * n; i++) utl[H[i].num].push_back(i);

    /*for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            printf("utl[%d][%d]:%d\n", i, j, utl[i][j]);
        }
    }*/

    //옆으로 인접
    for (int i = 0; i < n*2-1; i++) {
        if (H[i].x == H[i+1].x) {
            //if (i == 2) printf("**%d %d / %d %d\n", H[Utl_H(i)].y2, H[Utl_H(i + 1)].y1, Utl_H(i), Utl_H(i+1));
            if (H[Utl_H(i)].y2 >= H[Utl_H(i+1)].y1){
                printf("*Utl_H(%d):%d Utl_H(%d):%d\n", i, Utl_H(i), i + 1, Utl_H(i + 1));
                make_union_H(i, i+1);
                printf("Utl_H(%d):%d Utl_H(%d):%d\n", i, Utl_H(i), i + 1, Utl_H(i + 1));
            }
        }
    }

    //initialize
    for (int i = 1; i <= n; i++) utl[i].clear();
    for (int i = 0; i < 2 * n; i++) utl[R[i].num].push_back(i);

    //위아래로 인접
    for (int i = 0; i < n*2-1; i++) {
        if (R[i].y == R[i+1].y) {
            if (R[Utl_R(i+1)].x1 <= R[Utl_R(i)].x2) {
                printf("*Utl_R(%d):%d Utl_R(%d):%d\n", i, Utl_R(i), i + 1, Utl_R(i + 1));
                make_union_R(i, i+1);
                printf("Utl_R(%d):%d Utl_R(%d):%d\n", i, Utl_R(i), i + 1, Utl_R(i + 1));
            }
        }
    }   

    //소속된 영역에 값 합치기
    for (int i = 1; i <= n; i++) {
        if (find_union(i) == i) continue;
        area[find_union(i)] += area[i];
    }

    ll ret = 0;
    for (int i = 1; i <= n; i++) {
        printf("area[%d]:%lld, uni[%d]:%d\n", i, area[i],i,find_union(i));
        ret = max(ret, area[i]);
    }

    cout << ret;

    return 0;
}