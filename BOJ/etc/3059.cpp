//3059

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

    int n; cin >> n;

    while (n--) {
        int ret = 2015;
        map<char, bool> m;
        string s; cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if(!m[s[i]]) ret -= (int)s[i];
            m[s[i]] = true;
        }
        cout << ret << '\n';
    }

    return 0;
}