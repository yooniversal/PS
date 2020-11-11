//17938
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, p, t; cin >> n >> p >> t;
    int hand = 0, now = 0; //들어야 하는 팔 갯수, 현재 위치
    bool asc = true; //증가
    for (int i = 0; i < t; ++i) {
        now += hand;
        now %= 2 * n;
        if (asc) {
            ++hand;
            if (hand == 2 * n) asc = false;
        }
        else {
            --hand;
            if (hand == 1) asc = true;
        }
    }
    
    bool ret = false;
    int h1 = 2 * (p - 1), h2 = 2 * (p - 1) + 1;
    for (int cnt = 0; cnt < hand; ++cnt) {
        int here = now + cnt;
        here %= 2 * n;
        if (here == h1 || here == h2) {
            ret = true;
            break;
        }
    }
    if (ret) cout << "Dehet YeonJwaJe ^~^";
    else cout << "Hing...NoJam";

    return 0;
}