#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MOD = 1000000007;

void FASTIO() {
    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

bool isPeak(vector<int>& invests, int cur, int n) {
    if (cur+1 < n) return false;
    if (invests.size() - cur < n) return false;

    int prevLeft = invests[cur], prevRight = invests[cur];
    for (int i=cur, j=cur, cnt=0; cnt<n; i--, j++, cnt++) {
        if (invests[i] > prevLeft || invests[j] > prevRight) return false;
        prevLeft = invests[i];
        prevRight = invests[j];
    }
    return true;
 }

bool isValley(vector<int>& invests, int cur, int m) {
    if (cur+1 < m) return false;
    if (invests.size() - cur < m) return false;

    int prevLeft = invests[cur], prevRight = invests[cur];
    for (int i=cur, j=cur, cnt=0; cnt<m; i--, j++, cnt++) {
        if (invests[i] < prevLeft || invests[j] < prevRight) return false;
        prevLeft = invests[i];
        prevRight = invests[j];
    }
    return true;
}

int main() {
    FASTIO();

    int s, n, m; cin >> s >> n >> m;
    vector<int> invests;

    for (int i=0; i<s; i++) {
        int v; cin >> v;
        invests.push_back(v);
    }

    int peakCnt = 0, valleyCnt = 0;
    for (int i=0; i<s; i++) {
        if (isPeak(invests, i, n)) peakCnt++;
        if (isValley(invests, i, m)) valleyCnt++;
    }

    cout << peakCnt << " " << valleyCnt << '\n';

    return 0;
}