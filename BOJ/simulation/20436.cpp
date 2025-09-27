#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 987654321;
const int MOD = 1000000007;

map<char, ii> statusMap;
map<char, bool> isJaum;

void init() {
    statusMap['q'] = {0, 0};
    statusMap['w'] = {0, 1};
    statusMap['e'] = {0, 2};
    statusMap['r'] = {0, 3};
    statusMap['t'] = {0, 4};
    statusMap['y'] = {0, 5};
    statusMap['u'] = {0, 6};
    statusMap['i'] = {0, 7};
    statusMap['o'] = {0, 8};
    statusMap['p'] = {0, 9};

    statusMap['a'] = {1, 0};
    statusMap['s'] = {1, 1};
    statusMap['d'] = {1, 2};
    statusMap['f'] = {1, 3};
    statusMap['g'] = {1, 4};
    statusMap['h'] = {1, 5};
    statusMap['j'] = {1, 6};
    statusMap['k'] = {1, 7};
    statusMap['l'] = {1, 8};

    statusMap['z'] = {2, 0};
    statusMap['x'] = {2, 1};
    statusMap['c'] = {2, 2};
    statusMap['v'] = {2, 3};
    statusMap['b'] = {2, 4};
    statusMap['n'] = {2, 5};
    statusMap['m'] = {2, 6};

    isJaum['q'] = true;
    isJaum['w'] = true;
    isJaum['e'] = true;
    isJaum['r'] = true;
    isJaum['t'] = true;
    isJaum['a'] = true;
    isJaum['s'] = true;
    isJaum['d'] = true;
    isJaum['f'] = true;
    isJaum['g'] = true;
    isJaum['z'] = true;
    isJaum['x'] = true;
    isJaum['c'] = true;
    isJaum['v'] = true;
}

int dist(char a, char b) {
    ii aStatus = statusMap[a], bStatus = statusMap[b];
    return abs(aStatus.first - bStatus.first) + abs(aStatus.second - bStatus.second);
}

int getTime(char target, char& sl, char& sr) {
    if (isJaum[target]) {
        int dst = dist(target, sl);
        sl = target;
        return dst;
    }
    
    int dst = dist(target, sr);
    sr = target;
    return dst;
}

int main() {
    FASTIO;
    
    init();

    char sl, sr; cin>> sl >> sr;
    string s; cin >> s;

    int ret = 0;
    for (int i=0; i<s.size(); i++) {
        ret += getTime(s[i], sl, sr);
        ret++; // press
    }

    cout << ret << '\n';

    return 0;
}