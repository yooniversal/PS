//2840
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	string tmp(n, '?');
	int prev = -1;
	bool flag = false;
	for (int i = 0; i < k; ++i) {
		int s; char c; cin >> s >> c;
		if (i == 0) tmp[0] = c, prev = 0;
		else {
			if (tmp[(prev + s) % n] == '?' || tmp[(prev + s) % n] == c) {
				tmp[(prev + s) % n] = c;
				prev = (prev + s) % n;
			}
			else flag = true;
		}
	}
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (tmp[i] != '?' && tmp[i] == tmp[j])
				flag = true;

	if (flag) {
		cout << "!\n";
		return 0;
	}

	string ret;
	for (int i = prev; i >= 0; --i) ret += tmp[i];
	for (int i = n - 1; i > prev; --i) ret += tmp[i];
	cout << ret << '\n';

	return 0;
}