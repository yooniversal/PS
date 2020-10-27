//3019
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int c, p;
int a[101];

int solve() {
	int ret = 0;
	if (p == 1) {
		ret += c;
		for (int i = 0; i < c - 3; ++i) {
			bool flag = true;
			int tmp = a[i];
			for (int j = i+1; j < i + 4; ++j)
				if (a[i] != a[j]) {
					flag = false;
					break;
				}
			if (flag) ++ret;
		}
	}
	else if (p == 2) {
		for (int i = 0; i < c - 1; ++i)
			if (a[i] == a[i + 1])
				++ret;
	}
	else if (p == 3) {
		for (int i = 0; i < c - 2; ++i)
			if (a[i] == a[i + 1] && a[i] + 1 == a[i + 2])
				++ret;
		for (int i = 0; i < c - 1; ++i)
			if (a[i] == a[i + 1] + 1)
				++ret;
	}
	else if (p == 4) {
		for (int i = 0; i < c - 2; ++i)
			if (a[i]-1 == a[i + 1] && a[i+1] == a[i + 2])
				++ret;
		for (int i = 0; i < c - 1; ++i)
			if (a[i] + 1 == a[i + 1])
				++ret;
	}
	else if (p == 5) {
		for (int i = 0; i < c - 2; ++i)
			if (a[i] == a[i + 1] && a[i] == a[i + 2])
				++ret;
		for (int i = 0; i < c - 1; ++i)
			if (a[i] == a[i + 1] + 1)
				++ret;
		for (int i = 0; i < c - 1; ++i)
			if (a[i] + 1 == a[i + 1])
				++ret;
		for (int i = 0; i < c - 2; ++i)
			if (a[i] == a[i + 2] && a[i] == a[i + 1] + 1)
				++ret;
	}
	else if (p == 6) {
		for (int i = 0; i < c - 2; ++i)
			if (a[i] == a[i + 1] && a[i] == a[i + 2])
				++ret;
		for (int i = 0; i < c - 1; ++i)
			if (a[i] == a[i + 1])
				++ret;
		for (int i = 0; i < c - 2; ++i)
			if (a[i] + 1 == a[i + 1] && a[i + 1] == a[i + 2])
				++ret;
		for (int i = 0; i < c - 1; ++i)
			if (a[i]-2 == a[i + 1])
				++ret;
	}
	else {
		for (int i = 0; i < c - 2; ++i)
			if (a[i] == a[i + 1] && a[i] == a[i + 2])
				++ret;
		for (int i = 0; i < c - 1; ++i)
			if (a[i] == a[i + 1])
				++ret;
		for (int i = 0; i < c - 2; ++i)
			if (a[i] == a[i + 1] && a[i + 1]-1 == a[i + 2])
				++ret;
		for (int i = 0; i < c - 1; ++i)
			if (a[i] + 2 == a[i + 1])
				++ret;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> c >> p;
	for (int i = 0; i < c; ++i) cin >> a[i];
	cout << solve();

	return 0;
}