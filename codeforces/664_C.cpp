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
typedef long long ll;

bool bit[512];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);

	//input
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	//process
	for (int i = 0; i < n; i++) {
		vector<int> tmp(m);
		for (int j = 0; j < m; j++) {
			tmp[j] = (a[i] & b[j]);
		}

		if (i == 0) {
			for (int j = 0; j < m; j++)
				bit[tmp[j]] = true;
		}
		else {
			vector<int> now;
			for (int A = 0; A < 512; A++) {
				if (bit[A]) {
					for (int j = 0; j < m; j++)
						now.push_back(A | tmp[j]);
				}
			}
			memset(bit, false, sizeof(bit));
			for (int j = 0; j < now.size(); j++)
				bit[now[j]] = true;
		}
	}

	for (int i = 0; i < 512; i++)
		if (bit[i]) {
			cout << i;
			return 0;
		}

	return 0;
}