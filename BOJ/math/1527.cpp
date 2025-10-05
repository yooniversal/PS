#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int INF = 987654321;
const int MOD = 1000000007;

int smallDigitsResult(int digits) {
    if (digits <= 1) return 0;

    int ret = 0;

    for (int n=1; n<digits; n++) {
        ret += (1<<n);
    }

    return ret;
}

bool next(string& from) {
    if (from[from.size()-1] == '7') {
        bool isEnd = true;
        for (auto& c : from) {
            if (c == '7') continue;
            isEnd = false;
            break;
        }
        if (isEnd) return false; // 전체가 7 -> 다음 값 없음
        
        // 4477 -> 4744
        for (int i=from.size()-1; i>=0; i--) {
            if (from[i] == '7') {
                from[i] = '4';
            } else {
                from[i] = '7';
                break;
            }
        }
    } else {
        from[from.size()-1] = '7';
    }

    return true;
}

int getResult(ll target) {
    int digits = to_string(target).size();
    int ret = smallDigitsResult(digits);
    string base = "";
    for (int i=0; i<digits; i++) base += "4";

    if (stoll(base) > target) return ret;
    ret++;

    while (next(base)) {
        if (stoll(base) > target) return ret;
        ret++;
    }

    return ret;
}

int main() {
    FASTIO;

    int a, b; cin >> a >> b;
    cout << getResult(b) - getResult(a-1) << '\n';

    return 0;
}