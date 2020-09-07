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
		int n, k; cin >> n >> k;
		string s; cin >> s;
		bool ret = true;
		int zero = 0, one = 0;
		for (int i = 0; i < k; i++) {
			int tmp = -1;
			//s[j]와 s[j+k]는 같아야 함
			for (int j = i; j < n; j += k) {
				if (s[j] != '?') {
					if (tmp != -1 && tmp != s[j] - '0') {
						ret = false;
						break;
					}
					tmp = s[j] - '0';
				}
			}

			if (tmp != -1) {
				if (tmp == 0) zero++;
				else one++;
			}
		}

		if (max(zero, one) > k/2) {
			ret = false;
		}

		if(ret) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}