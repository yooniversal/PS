#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

int n, m;
char a[11][11];
bool deleted[11][11], deletedRow[11], deletedCol[11];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};

bool OOB(int x, int y) {
    return x<0 || x>=n || y<0 || y>=m;
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<m; j++) {
           a[i][j] = s[j];
        }
    }

    vector<ii> crushed;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        if (a[i][j] == '.') continue;

        int seaCnt = 0;
        for (int d=0; d<4; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            if (OOB(nx, ny) || a[nx][ny] == '.') seaCnt++;
        }

        if (seaCnt >= 3) crushed.push_back({i, j});
    }

    for (auto& xy : crushed) a[xy.first][xy.second] = '.';

    int firstLandRow = -1, lastLandRow = n-1;
    int firstLandCol = -1, lastLandCol = m-1;

    for (int i=0; i<n; i++) {
        bool flag = false;
        for (int j=0; j<m; j++) {
            if (a[i][j] != '.') {
                flag = true;
                break;
            }
        }
        if (flag) {
            if (firstLandRow == -1) firstLandRow = i;
            lastLandRow = i;
        }
    }

    for (int i=0; i<m; i++) {
        bool flag = false;
        for (int j=0; j<n; j++) {
            if (a[j][i] != '.') {
                flag = true;
                break;
            }
        }
        if (flag) {
            if (firstLandCol == -1) firstLandCol = i;
            lastLandCol = i;
        }
    }

    for (int i=firstLandRow; i<=lastLandRow; i++) {
        for (int j=firstLandCol; j<=lastLandCol; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }

    return 0;
}