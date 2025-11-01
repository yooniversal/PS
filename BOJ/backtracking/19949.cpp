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

vi a(10);
int ret;

void DFS(int cur, int prev, int cnt, int score) {
    if (cur >= 10) {
        if (score >= 5) ret++;
        return;
    }

    for (int i=1; i<=5; i++) {
        if (i == prev && cnt == 2) continue;
        int nextScore = i == a[cur] ? score+1 : score;
        if (i == prev) DFS(cur+1, i, cnt+1, nextScore);
        else DFS(cur+1, i, 1, nextScore);
    }
}

int main() {
    FASTIO;

    for (int i=0; i<10; i++) cin >> a[i];
    DFS(0, 0, 0, 0);
    cout << ret << '\n';

    return 0;
}