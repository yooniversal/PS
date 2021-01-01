//3108
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 500001, INF = 1000000001, MOD = 1234567;

int n, uni[1001], a[1001][1001];
bool chk[1001];

int find(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find(uni[a]);
}

int makeUnion(int a, int b) {
	a = find(a), b = find(b);
	if (a <= b) return uni[b] = a;
	return uni[a] = b;
}

void Squ(int x1, int y1, int x2, int y2, int cnt) {
	for (int i : {x1, x2}) for (int j = y1; j <= y2; ++j) {
		if (a[i][j] != -1) a[i][j] = makeUnion(a[i][j], cnt);
		else a[i][j] = cnt;
	}
	for (int i = x1 + 1; i <= x2 - 1; ++i) for (int j : {y1, y2}) {
		if (a[i][j] != -1) a[i][j] = makeUnion(a[i][j], cnt);
		else a[i][j] = cnt;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(a, -1, sizeof(a));
	for(int i=1; i<=1000; ++i) uni[i] = i;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		x1 += 500, y1 += 500, x2 += 500, y2 += 500;
		Squ(x1, y1, x2, y2, i);
	}

	int ret = 0;
	for (int i = 0; i < 1001; ++i) for (int j = 0; j < 1001; ++j) {
		if (a[i][j] == -1) continue;
		if (chk[find(a[i][j])]) continue;
		chk[find(a[i][j])] = true;
		++ret;
	}

	if (a[500][500] != -1) --ret;

	cout << ret << '\n';

	return 0;
}