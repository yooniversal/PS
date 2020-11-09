//12886
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 500001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int chk[1501][1501];
vi T;
int sum;

int BFS() {
    queue<ii> q;
    q.push({ T[0], T[1] });
    while (!q.empty()) {
        int a = q.front().first, b = q.front().second, c = sum-(a+b); q.pop();
        if (a==c) return 1;
        if (chk[a][b]) continue;
        chk[a][b] = true;

        vi tmp(3);
        if (a != b) {
            tmp[0] = a*2, tmp[1] = b-a, tmp[2] = c;
            sort(tmp.begin(), tmp.end());
            q.push({ tmp[0], tmp[1] });
        }
        if (a != c) {
            tmp[0] = a*2, tmp[1] = b, tmp[2] = c-a;
            sort(tmp.begin(), tmp.end());
            q.push({ tmp[0], tmp[1] });
        }
        if (b != c) {
            tmp[0] = a, tmp[1] = b*2, tmp[2] = c-b;
            sort(tmp.begin(), tmp.end());
            q.push({ tmp[0], tmp[1] });
        }
    }
    return 0;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    T.resize(3);
    cin >> T[0] >> T[1] >> T[2];
    sum = T[0] + T[1] + T[2];
    sort(T.begin(), T.end());
    cout << BFS();

    return 0;
}