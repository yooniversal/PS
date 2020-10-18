//2602
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

string need, r1, r2;
ll cache[105][25][2];

ll f(int a, int b, int turn) {
	if (a > r1.size()) return 0;
	if (b == need.size()) return 1;
	ll& ret = cache[a][b][turn];
	if (ret != -1) return ret;
	ret = 0;
	if (turn == 0) {
		for (int i = a; i < r1.size(); ++i)
			if (r1[i] == need[b])
				ret += f(i+1, b + 1, 1);
	}
	else {
		for (int i = a; i < r2.size(); ++i)
			if (r2[i] == need[b])
				ret += f(i+1, b + 1, 0);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> need >> r1 >> r2;
	cout << f(0, 0, 0) + f(0, 0, 1);

	return 0;
}