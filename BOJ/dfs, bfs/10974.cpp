//10974

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
#define MAX 10001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool chk[9];
int n, cnt;
vi arr;

void dfs(int a) {
    if (cnt == n) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (chk[i]) continue;
        cnt++;
        arr.push_back(i);
        chk[i] = true;
        dfs(i);
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
    dfs(0);

    return 0;
}