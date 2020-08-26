//10819

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
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool chk[9];
int n, cnt;
vi arr, input;
ll ret;

void dfs(int a) {
    if (cnt == n) {
        ll tmp = 0;
        for (int i = 0; i < n-1; i++) {
            tmp += abs(arr[i]-arr[i+1]);
        }
        ret = max(ret, tmp);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        cnt++;
        arr.push_back(input[i]);
        chk[i] = true;
        dfs(i+1);
        chk[i] = false;
        cnt--;
        arr.erase(arr.begin() + cnt);
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++) cin >> input[i];
    dfs(0);
    cout << ret;

    return 0;
}