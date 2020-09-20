//18808
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 41
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vvi board;
vvi sticker[101];
int n, m, k;

//90µµ È¸Àü
vvi rotate(vvi& sample) {
	int ROW = sample.size();
	int COL = sample[0].size();

	vvi v;
	for (int i = 0; i < COL; ++i) {
		vi tmp(ROW);
		int rp = 0;
		for (int j = ROW - 1; j >= 0; --j) {
			tmp[rp++] = sample[j][i];
		}
		v.push_back(tmp);
	}

	return v;
}

bool canPut(int x, int y, vvi& v) {
	for (int i = x; i < v.size() + x; ++i)
		for (int j = y; j < v[0].size() + y; ++j)
			if (v[i-x][j-y] && board[i][j]) return false;

	for (int i = x; i < v.size() + x; ++i)
		for (int j = y; j < v[0].size() + y; ++j)
			if(v[i-x][j-y]) board[i][j] = v[i-x][j-y];

	return true;
}

void solve() {
	for (int num = 0; num < k; ++num) {
		vvi STICKER = sticker[num];
		for (int r = 0; r < 4; ++r) {
			int xMAX = n - STICKER.size();
			int yMAX = m - STICKER[0].size();

			for (int x = 0; x <= xMAX; ++x) {
				for (int y = 0; y <= yMAX; ++y) {
					if (canPut(x, y, STICKER)) { x = n; y = m; r = 4; }
				}
			}
			STICKER = rotate(STICKER);
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		int r, c; cin >> r >> c;
		for (int row = 0; row < r; ++row) {
			vi v(c, 0);
			for (int col = 0; col < c; ++col)
				cin >> v[col];
			sticker[i].push_back(v);
		}
	}

	board.resize(n);
	for (int i = 0; i < n; ++i)
		board[i].resize(m, 0);

	solve();

	int ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (board[i][j])
				++ret;
	cout << ret;

	return 0;
}