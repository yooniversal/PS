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

int n = 1;
int a[1000005];
int aliveCnt;
vector<int> dimensions, dead;

bool finished() {
    return aliveCnt <= 0;
}

bool OOB(int cur, int d, int multipliedDimension) {
    if ((cur / multipliedDimension) != ((cur + d) / multipliedDimension)) return true;
    return (cur + d) < 0 || (cur + d) >= n;
}

void virus() {
    queue<int> q;
    for (auto& start : dead) q.push(start);
    dead.clear();

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        int next = 1;
        int multipliedDimension = 1;
        for (auto& dimension : dimensions) {
            multipliedDimension *= dimension;
            if (next > n) break;

            for (auto& d : {next, -next}) {
                int ni = cur + d;
                if (OOB(cur, d, multipliedDimension) || a[ni] != 0) continue;
                a[ni] = 1;
                aliveCnt--;
                dead.push_back(ni);
            }

            next *= dimension;
        }
    }
}

int main() {
    FASTIO;

    memset(a, -1, sizeof(a));
    
    for (int i=0; i<11; i++) {
        int v; cin >> v;
        n *= v;
        dimensions.push_back(v);
    }

    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] == 0) aliveCnt++;
        else if (a[i] == 1) dead.push_back(i);
    }

    int days = 0;
    int prevAliveCnt = aliveCnt;
    while (!finished()) {
        virus();
        days++;

        if (prevAliveCnt == aliveCnt) {
            cout << -1 << '\n';
            return 0;
        }
        prevAliveCnt = aliveCnt;
    }

    cout << days << '\n';

    return 0;
}