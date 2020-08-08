//2484

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

int dice[7];

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    vector<int> ans;
    while (t--) {
        int n; vector<int> arr;
        for (int i = 0; i < 4; i++) {
            cin >> n;
            dice[n]++;
            arr.push_back(i);
        }

        int mode = 0, ver = 0;
        for (int i = 1; i <= 6; i++) {
            if (dice[i] == 1) {
                mode = max(mode, 1);
            }
            else if (dice[i] == 2) {
                mode = max(mode, 2); ver++;
            }
            else if (dice[i] == 3) {
                mode = max(mode, 3);
            }
            else if (dice[i] == 4) {
                mode = max(mode, 4);
            }
        }

        //cout << "mode:" << mode << '\n';

        if (mode == 4) {
           ans.push_back(50000 + n * 5000);
        }
        else if (mode == 3) {
            int point;
            for (int i = 1; i <= 6; i++)
                if (dice[i] == 3) point = i;
            ans.push_back(10000 + point * 1000);
        }
        else if (mode == 2) {
            if (ver == 2) {
                int a = 2000;
                for (int i = 1; i <= 6; i++)
                    if (dice[i] == 2) a += 500 * i;
                ans.push_back(a);
            }
            else {
                int a = 1000;
                for (int i = 1; i <= 6; i++)
                    if (dice[i] == 2) a += 100 * i;
                ans.push_back(a);
            }
        }
        else {
            int a = 0;
            for (int i = 1; i <= 6; i++)
                if (dice[i] == 1) a = max(a, i);
            ans.push_back(100 * a);
        }

        fill(dice, dice + 7, 0);
    }

    int a = 0;
    for (auto& ret : ans)
        a = max(a, ret);
    cout << a;

    return 0;
}