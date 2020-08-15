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
#define MAXSIZE 100001
typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;

		map<int, int> key;
		vector<int> pre(n + 1);
		int res = 0;

		pre[0] = 0;
		for (int i = 0; i < n; i++) {
			pre[i+1] += pre[i] + (s[i] - '0');
		}

		for (int i = 1; i <= n; i++) {
			key[pre[i-1] - i]++;
			res += key[pre[i] - i - 1];
		}

		cout << res << '\n';
    }
	
	return 0;
}