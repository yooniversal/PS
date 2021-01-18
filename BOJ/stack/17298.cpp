//17298
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

stack<int> s;
int ret[MAX], route[MAX];

ii solve(int cur, int idx) {
	if (idx == 0 || idx == -1) return { -1, -1 };
	if (cur < ret[idx]) return { ret[idx], idx };
	return solve(cur, route[idx]);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		s.push(a);
	}

	int idx = n-1, prev = s.top(); s.pop();
	ret[n - 1] = -1;
	for (int i = n - 2; i >= 0; --i) {
		if (s.top() >= prev) {
			if(s.top() < ret[i + 1]) ret[i] = ret[i+1], route[i] = idx;
			else {
				ii tmp = solve(s.top(), idx);
				ret[i] = tmp.first;
				route[i] = idx = tmp.second;
			}
		}
		else {
			ret[i] = prev;
			route[i] = idx = i + 1;
		}
		prev = s.top();
		s.pop();
	}

	for (int i = 0; i < n; ++i) cout << ret[i] << ' ';
	cout << '\n';

	return 0;
}