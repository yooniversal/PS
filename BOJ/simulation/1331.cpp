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

set<string> chk;

bool checkValid(string& prev, string& cur) {
    int dx = abs(prev[0] - cur[0]);
    int dy = abs(prev[1] - cur[1]);
    if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) return true;
    return false;
}

int main() {
    FASTIO;
    
    bool ret = true;
    string prev; cin >> prev;
    string first = prev;
    chk.insert(prev);
    
    for (int i=0; i<35; i++) {
        string cur; cin >> cur;

        if (chk.find(cur) != chk.end()) ret = false;
        if (!checkValid(prev, cur)) ret = false;
        
        prev = cur;
        chk.insert(cur);
    }

    if (!checkValid(first, prev)) ret = false;

    if (ret) cout << "Valid\n";
    else cout << "Invalid\n";

    return 0;
}