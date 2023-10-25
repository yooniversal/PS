#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;

struct S {
    bool red;
    bool side;
    int cnt;
    S(bool red, bool side, int cnt): red(red), side(side), cnt(cnt) {}
};

const int INF = 987654321;

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n; cin >> n;
    string s; cin >> s;

    vector<S> red, blue;
    char before = 'A';
    int start_idx = 0;
    int cnt = 0;
    for(int i=0; i<n; ++i) {
        if(cnt == 0) {
            ++cnt;
            start_idx = 0;
            before = s[i];
            continue;
        }

        if(before != s[i]) {
            if(before == 'R') red.push_back(S(true, start_idx==0 || start_idx==n-1, cnt));
            else blue.push_back(S(false, start_idx==0 || start_idx==n-1, cnt));
            cnt = 1;
            start_idx = i;
            before = s[i];

            if(i == n-1) {
                if(s[i] == 'R') red.push_back(S(true, true, cnt));
                else blue.push_back(S(false, true, cnt));
            }
            continue;
        }

        ++cnt;
        if(i == n-1) {
            if(s[i] == 'R') red.push_back(S(true, true, cnt));
            else blue.push_back(S(false, true, cnt));
        }
    }

    int ret = INF;
    int side_cnt = INF;
    int side_update_cnt = 0;
    int sum = 0;
    for(int i=0; i<red.size(); ++i) {
        if(red[i].side) {
            side_cnt = min(side_cnt, red[i].cnt);
            ++side_update_cnt;
            continue;
        }
        sum += red[i].cnt;
    }
    if(side_update_cnt == 2) sum += side_cnt;
    ret = min(ret, sum);

    side_cnt = INF;
    side_update_cnt = 0;
    sum = 0;
    for(int i=0; i<blue.size(); ++i) {
        if(blue[i].side) {
            side_cnt = min(side_cnt, blue[i].cnt);
            ++side_update_cnt;
            continue;
        }
        sum += blue[i].cnt;
    }
    if(side_update_cnt == 2) sum += side_cnt;
    ret = min(ret, sum);

    cout << ret << '\n';

    return 0;
}