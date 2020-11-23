//12871
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int GCD(int a, int b) {
	while (b) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, t; cin >> s >> t;
	if (s.size() < t.size()) swap(s, t);
	int to = s.size() * t.size() / GCD(s.size(), t.size());
	string ss; ss = s;
	while (s.size() != to) s += ss;
	string tt; tt = t;
	while (t.size() != to) t += tt;
	for (int i = 0; i < to; ++i) {
		if (s[i] != t[i]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;

	return 0;
}