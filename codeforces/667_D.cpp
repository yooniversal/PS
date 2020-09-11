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
#define MAX 100001
typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		ll n, s; cin >> n >> s;
		string S = to_string(n);
		ll cmp = 0, num = 0, alldigit = 0;
		for (int i = 0; i < S.size(); i++) alldigit += S[i] - '0';
		if (alldigit <= s) { cout << 0 << '\n'; continue; }
		for (int i = 0; i < S.size(); i++) {
			cmp += 1LL*(S[i] - '0');
			if (cmp >= s) {
				ll big = 1;
				for (int j = i; j < S.size(); j++) {
					num = num * 10 + 1LL * (S[j] - '0');
					big *= 10;
				}
				cout << big - num << '\n';
				break;
			}
		}
	}

	return 0;
}