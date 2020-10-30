//2916
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, k;
bool maked[365];
vi a;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		maked[a[i]] = true;
	}

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int add = (a[i] + a[j]) % 360;
			int sub = a[i] - a[j], sub2 = a[j] - a[i];
			if (sub < 0) sub += 360;
			if (sub2 < 0) sub2 += 360;
			if (!maked[add]) {
				maked[add] = true;
				q.push(add);
			}
			if (!maked[sub]) {
				maked[sub] = true;
				q.push(sub);
			}
			if (!maked[sub2]) {
				maked[sub2] = true;
				q.push(sub2);
			}
		}
	}

	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < a.size(); ++i) {
			int add = (a[i] + x) % 360;
			int sub = a[i] - x, sub2 = x - a[i];
			if (sub < 0) sub += 360;
			if (sub2 < 0) sub2 += 360;
			if (!maked[add]) {
				maked[add] = true;
				q.push(add);
			}
			if (!maked[sub]) {
				maked[sub] = true;
				q.push(sub);
			}
			if (!maked[sub2]) {
				maked[sub2] = true;
				q.push(sub2);
			}
		}
		a.push_back(x);
	}

	while (k--) {
		int target; cin >> target;
		if (maked[target]) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}