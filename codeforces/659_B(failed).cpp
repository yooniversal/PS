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

typedef long long ll;

int n, k, l, fir;
bool ans;
vector<int> d, p;

struct dual {
	int cur, time;

	dual(int c, int t) : cur(c), time(t) {}
};

void sol(int c, int t) {
	queue<dual> q;
	q.push({ c, t });
	while (!q.empty()) {
		int cur = q.front().cur;
		int time = q.front().time;
		q.pop();
		if (ans) return;
		//if (cur >= n+1) return;
		//cout << "cur:" << cur << " d[cur]:" << d[cur] << " p[]:" << p[time % (2 * k)] << '\n';
		if (cur != 0) {
			if (d[cur] + p[time % (2 * k)] <= l) {
				if (cur == n) {
					ans = true;
					return;
				}

				if (d[cur + 1] + p[(time + 1) % (2 * k)] <= l) {
					q.push({ cur+1, time + 1 });
					if (d[cur] + p[(time + 1) % (2 * k)] != d[cur]) q.push({ cur, time + 1 });
				}
				else q.push({ cur, time + 1 });
			}
		}
		else {
			fir++;
			if (fir < 2 * k + 1) q.push({ cur, time + 1 });
			q.push({ cur+1, time + 1 });
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		fir = 0;
		ans = false;

		cin >> n >> k >> l;
		
		d.resize(n + 2, 0); p.resize(2 * k);

		bool cannot = false;
		for (int i = 1; i <= n; i++) {
			cin >> d[i];
			if (d[i] > l) cannot = true;
		}

		for (int i = 0; i < 2*k; i++) {
			if (i <= k) {
				if (i == 0) p[i] = 0;
				else p[i] = p[i - 1] + 1;
			}
			else {
				p[i] = p[i - 1] - 1;
			}
		}
		
		if(!cannot) sol(0, 0);

		if (ans) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}

	return 0;
}