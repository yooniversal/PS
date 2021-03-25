//20061
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

bool block[2][6][4];
int sum[2][6], ret;

// mode :: 초록:0, 파랑:1
void process(int mode, int t, int x, int y) {
	if (mode == 1) {
		int tx = y, ty = 3 - x;
		x = tx, y = ty;
		if (t == 2) t = 3;
		else if (t == 3) t = 2, --y;
	}

	int nx = 1, ny = y;
	if (t == 1) {
		while (nx <= 5 && !block[mode][nx][ny]) ++nx;
		--nx;
		block[mode][nx][ny] = true;
		++sum[mode][nx];

		if (nx == 1) {
			for (int i = 4; i >= 1; --i)
				sum[mode][i + 1] = sum[mode][i];
			for (int c = 0; c < 4; ++c) {
				for (int r = 4; r >= 1; --r) {
					block[mode][r + 1][c] = block[mode][r][c];
				}
			}
			sum[mode][nx] = 0;
			block[mode][nx][ny] = false;
		}
		else {
			int cur = nx;
			if (sum[mode][cur] == 4) {
				++ret;
				for (int r = cur - 1; r >= 1; --r)
					sum[mode][r + 1] = sum[mode][r];
				for (int c = 0; c < 4; ++c) {
					for (int r = cur - 1; r >= 1; --r) {
						block[mode][r + 1][c] = block[mode][r][c];
					}
				}
			}
		}
	}
	else if (t == 2) {
		while (nx <= 5 && !block[mode][nx][ny] && !block[mode][nx][ny + 1]) ++nx;
		--nx;
		sum[mode][nx] += 2;
		block[mode][nx][ny] = block[mode][nx][ny + 1] = true;

		if (nx == 1) {
			for (int r = 4; r >= 0; --r)
				sum[mode][r + 1] = sum[mode][r];
			for (int c = 0; c < 4; ++c) {
				for (int r = 4; r >= 0; --r) {
					block[mode][r + 1][c] = block[mode][r][c];
				}
			}
		}
		else {
			if (sum[mode][nx] == 4) {
				++ret;
				int cur = nx;
				sum[mode][cur] = 0;
				for (int r = cur - 1; r >= 1; --r)
					sum[mode][r + 1] = sum[mode][r];
				for (int c = 0; c < 4; ++c) {
					for (int r = cur - 1; r >= 1; --r) {
						block[mode][r + 1][c] = block[mode][r][c];
					}
				}
			}
		}
	}
	else {
		while (nx <= 5 && !block[mode][nx][ny]) ++nx;
		--nx;
		++sum[mode][nx - 1], ++sum[mode][nx];
		block[mode][nx - 1][ny] = block[mode][nx][ny] = true;

		// (0~1)겹침
		if (nx == 2) {
			// 점수 계산
			if (sum[mode][nx] == 4) {
				++ret;
				sum[mode][nx] = 0;
				for (int r = nx - 1; r >= 0; --r)
					sum[mode][r + 1] = sum[mode][r];
				for (int c = 0; c < 4; ++c) {
					for (int r = nx - 1; r >= 0; --r) {
						block[mode][r + 1][c] = block[mode][r][c];
					}
				}
			}
			// 다 찬거 아니면 연한 칸 처리만 하면 됨
			else {
				for (int r = 4; r >= 0; --r)
					sum[mode][r + 1] = sum[mode][r];
				for (int c = 0; c < 4; ++c) {
					for (int r = 4; r >= 0; --r) {
						block[mode][r + 1][c] = block[mode][r][c];
					}
				}
			}
		}
		// (0~1)에만 있음
		else if (nx == 1) {
			for (int r = 3; r >= 0; --r)
				sum[mode][r + 2] = sum[mode][r];
			for (int c = 0; c < 4; ++c) {
				for (int r = 3; r >= 0; --r) {
					block[mode][r + 2][c] = block[mode][r][c];
				}
			}

			sum[mode][nx - 1] = sum[mode][nx] = 0;
			block[mode][nx - 1][ny] = block[mode][nx][ny] = false;
		}
		// 안겹침
		else {
			if (sum[mode][nx - 1] == 4 && sum[mode][nx] == 4) {
				ret += 2;
				for (int r = nx - 2; r >= 0; --r)
					sum[mode][r + 2] = sum[mode][r];
				for (int c = 0; c < 4; ++c) {
					for (int r = nx - 2; r >= 0; --r) {
						block[mode][r + 2][c] = block[mode][r][c];
					}
				}
			}
			else if (sum[mode][nx - 1] == 4 || sum[mode][nx] == 4) {
				++ret;
				int cur = sum[mode][nx - 1] == 4 ? nx - 1 : nx;
				for (int r = cur - 1; r >= 1; --r)
					sum[mode][r + 1] = sum[mode][r];
				for (int c = 0; c < 4; ++c) {
					for (int r = cur - 1; r >= 1; --r) {
						block[mode][r + 1][c] = block[mode][r][c];
					}
				}
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	while (n--) {
		int t, x, y; cin >> t >> x >> y;
		process(0, t, x, y);
		process(1, t, x, y);
	}

	cout << ret << '\n';
	int bgsum = 0;
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 2; ++k)
				bgsum += block[k][i][j];
	cout << bgsum << '\n';

	return 0;
}