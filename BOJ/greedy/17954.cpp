//17954
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

struct P {
    int r, c, dir; //dir: 0이 왼쪽, 1이 오른쪽
};

vvi tube;

P search(P a, P b) {
    if (tube[a.r][a.c] > tube[b.r][b.c]) return b;
    return a;
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    if (n == 1) {
        cout << 2 << '\n' << 1 << '\n' << 2;
        return 0;
    }
    tube.resize(2, vi(n, 0));
    tube[0][0] = 2 * n - 3;
    tube[0][n - 1] = 2 * n - 2;
    tube[1][0] = 2 * n - 1;
    tube[1][n - 1] = 2 * n;
    int cnt = 2*n-4;
    for (int r = 0; r <= 1; ++r)
        for (int c = 1; c < n - 1; ++c)
            tube[r][c] = cnt--;

    int sum = 0;
    for (int i = 1; i <= 2 * n; ++i)
        sum += i;

    int l1 = 0, l2 = 0, r1 = n - 1, r2 = n - 1;
    ll ret = 0, time = 0;
    while (l1 <= r1 || l2 <= r2) {
        P turn = { -1, -1, -1 }, turn2 = { -1, -1, -1 };
        if (l1 < r1) turn = search({ 0, l1, 0 }, { 0, r1, 1 });
        else if (l1 == r1) turn = { 0, l1, 0 };
        if (l2 < r2) turn2 = search({ 1, l2, 0 }, { 1, r2, 1 });
        else if (l2 == r2) turn2 = { 1, l2, 0 };
        if(turn.r != -1 && turn2.r != -1) turn = search(turn, turn2);
        else {
            if (turn.r == -1) turn = turn2;
        }

        sum -= tube[turn.r][turn.c];
        ret += sum * (++time);
        if (turn.dir == 1) {
            if (turn.r == 0) --r1;
            else --r2;
        }
        else {
            if (turn.r == 0) ++l1;
            else ++l2;
        }
    }

    cout << ret << '\n';
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j)
            cout << tube[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}