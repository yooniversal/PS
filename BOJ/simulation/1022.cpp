//1022
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int digit(int n) {
	int ret = 0;
	while (n) {
		++ret;
		n /= 10;
	}
	return ret;
}

int solve(int x, int y) {
	int N = max(abs(x), abs(y)); //N번째 사각형
	if (x == y) {	
		if (x < 0) return (N * 2 + 1) * (N * 2 + 1) - 4 * N;
		else return (N * 2 + 1) * (N * 2 + 1);
	}
	else if (x == -N && y == N) return (N * 2 + 1) * (N * 2 + 1) - 6 * N;
	else if (x == N && y == -N) return (N * 2 + 1) * (N * 2 + 1) - 2 * N;
	else {
		if (x == -N) return (N * 2 + 1) * (N * 2 + 1) - 6 * N + (N - y);
		else if (x == N) return (N * 2 + 1) * (N * 2 + 1) - (N - y);
		else if (y == -N) return (N * 2 + 1) * (N * 2 + 1) - 4 * N + (x + N);
		else if (y == N) return (N * 2 + 1) * (N * 2 + 1) - 6 * N - (x + N);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
	vvi ret(r2 - r1 + 1, vi(c2 - c1 + 1, 0));
	for (int i = r1, r = 0; i <= r2; ++i, ++r)
		for (int j = c1, c = 0; j <= c2; ++j, ++c)
			ret[r][c] = solve(i, j);

	//자릿수 카운트
	int maxDigit = 0;
	for (int i = 0; i < ret.size(); ++i)
		for (int j = 0; j < ret[0].size(); ++j)
			maxDigit = max(maxDigit, digit(ret[i][j]));
	
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[0].size(); ++j)
			if (maxDigit == digit(ret[i][j])) cout << ret[i][j] << " ";
			else {
				int blank = maxDigit - digit(ret[i][j]);
				while (blank--) cout << " ";
				cout << ret[i][j] << " ";
			}
		cout << '\n';
	}


	return 0;
}