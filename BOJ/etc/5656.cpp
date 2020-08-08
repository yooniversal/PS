//5656

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

    int cnt = 1;
    while (1) {
        int a, b; string oper;
        cin >> a;
        cin >> oper;
        cin >> b;

        if (oper == "E") break;
        else if (oper == ">") {
            if (a > b) cout << "Case " << cnt << ": true" << '\n';
            else cout << "Case " << cnt << ": false" << '\n';
        }
        else if (oper == ">=") {
            if (a >= b) cout << "Case " << cnt << ": true" << '\n';
            else cout << "Case " << cnt << ": false" << '\n';
        }
        else if (oper == "<") {
            if (a < b) cout << "Case " << cnt << ": true" << '\n';
            else cout << "Case " << cnt << ": false" << '\n';
        }
        else if (oper == "<=") {
            if (a <= b) cout << "Case " << cnt << ": true" << '\n';
            else cout << "Case " << cnt << ": false" << '\n';
        }
        else if (oper == "==") {
            if (a == b) cout << "Case " << cnt << ": true" << '\n';
            else cout << "Case " << cnt << ": false" << '\n';
        }
        else {
            if (a != b) cout << "Case " << cnt << ": true" << '\n';
            else cout << "Case " << cnt << ": false" << '\n';
        }
        
        cnt++;
    }

    return 0;
}