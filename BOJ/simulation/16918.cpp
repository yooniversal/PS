//16918
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1000000007;

char a[201][201];
int bomb[201][201];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int r, c, k;

bool OOB(int x, int y) { return x < 0 || x >= r || y < 0 || y >= c; }

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c >> k;
	for (int i = 0; i < r; ++i) {
		string s; cin >> s;
		for (int j = 0; j < c; ++j) {
			a[i][j] = s[j];
			if (a[i][j] == 'O') bomb[i][j] = 3;
		}
	}

	vii del;
	for (int cur = 1; cur <= k; ++cur) {
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
			//1초 지남
			if (a[i][j] == 'O') {
				--bomb[i][j];

				//폭발
				if (bomb[i][j] == 0) {
					a[i][j] = '.';
					for (int d = 0; d < 4; ++d) {
						int nx = i + dx[d], ny = j + dy[d];
						if (OOB(nx, ny)) continue;
						if (a[nx][ny] == '.') continue;
						del.push_back({ nx, ny });
					}
				}
			}

			//설치되지 않은 칸에 모두 설치
			if (cur >= 2 && cur % 2 == 0)
				if (a[i][j] == '.') a[i][j] = 'O', bomb[i][j] = 3;
		}

		//폭발 처리
		for (int i = 0; i < del.size(); ++i)
			a[del[i].first][del[i].second] = '.', bomb[del[i].first][del[i].second] = 0;
		del.clear();
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << a[i][j];
		}
		cout << '\n';
	}

	return 0;
}