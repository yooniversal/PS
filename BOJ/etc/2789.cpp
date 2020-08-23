//2789

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
#define MAX 20005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s; cin >> s;
    map<char, bool> m;
    m['C'] = true;
    m['A'] = true;
    m['M'] = true;
    m['B'] = true;
    m['R'] = true;
    m['I'] = true;
    m['D'] = true;
    m['G'] = true;
    m['E'] = true;

    for (int i = 0; i < s.size(); i++) {
        if (!m[s[i]]) cout << s[i];
    }

    return 0;
}