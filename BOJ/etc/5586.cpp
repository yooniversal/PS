//5586

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
#define MAXSIZE 500001
typedef long long ll;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s; cin >> s;

    int ja = 0, ia = 0;
    for (int i = 0; i < s.size()-2; i++) {
        if (s[i] == 'J') {
            if (s[i + 1] == 'O' && s[i + 2] == 'I') ja++;
        }
        if (s[i] == 'I') {
            if (s[i + 1] == 'O' && s[i + 2] == 'I') ia++;
        }
    }
    cout << ja << '\n' << ia;

    return 0;
}