#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int INF = 987654321;
const int MOD = 1000000007;

void rotate(vvi& a, bool direction) {
    int n = a.size();
    vvi tmp(n, vi(n, 0));

    if (direction) {
        // 가운데 행 -> 주 대각선
        for (int x=0, y=0; x<=n-1 && y<=n-1; x++, y++) {
            tmp[x][y] = a[n/2][y];
        }

        // 주 대각선 -> 가운데 열
        for (int x=0, y=0; x<=n-1 && y<=n-1; x++, y++) {
            tmp[x][n/2] = a[x][y];
        }

        // 가운데 열 -> 부 대각선
        for (int x=0, y=n-1; x<=n-1 && y>=0; x++, y--) {
            tmp[x][y] = a[x][n/2];
        }

        // 부 대각선 -> 가운데 행
        for (int x=n-1, y=0; x>=0 && y<=n-1; x--, y++) {
            tmp[n/2][y] = a[x][y];
        }
    } else {
        // 가운데 행 -> 부 대각선
        for (int x=n-1, y=0; x>=0 && y<=n-1; x--, y++) {
            tmp[x][y] = a[n/2][y];
        }

        // 부 대각선 -> 가운데 열
        for (int x=0, y=n-1; x<=n-1 && y>=0; x++, y--) {
            tmp[x][n/2] = a[x][y];
        }

        // 가운데 열 -> 주 대각선
        for (int x=0, y=0; x<=n-1 && y<=n-1; x++, y++) {
            tmp[x][y] = a[x][n/2];
        }

        // 주 대각선 -> 가운데 행
        for (int x=0, y=0; x<=n-1 && y<=n-1; x++, y++) {
            tmp[n/2][y] = a[x][y];
        }
    }

    for (int x=0; x<n; x++) for (int y=0; y<n; y++) {
        if (tmp[x][y] != 0) continue;
        tmp[x][y] = a[x][y];
    }

    a = tmp;
}

void print(vvi& a) {
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    FASTIO;

    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        d %= 360;
        vvi a(n, vi(n, 0));
        
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> a[i][j];

        if (d == 0) {
            print(a);
            continue;
        }

        int rotationCnt = abs(d) / 45;
        if (d > 0) for (int i=0; i<rotationCnt; i++) rotate(a, true);            
        else for (int i=0; i<rotationCnt; i++) rotate(a, false);

        print(a);
    }

    return 0;
}