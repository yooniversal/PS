#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int INF = 987654321;

string s;

void f(int l, int r) {
    int len = (r - l + 1) / 3;
    if (len <= 0) return;
    for (int i=l+len; i<l+len*2; i++) s[i] = ' ';
    f(l, l + len - 1);
    f(l + len * 2, r);
}

int main() {

    cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n; 
    while (cin >> n) {
        s = "";
        int len = 1;
        for (int i=0; i<n; i++) len *= 3;
        for (int i=0; i<len; i++) s += '-';

        f(0, len-1);
        cout << s << '\n';
    }

    return 0;
}