//11559
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

const int n = 12, m = 6;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int base[6]; // 쌓인 블럭의 최대 높이를 가리키는 인덱스
char a[12][6];
bool chk[12][6];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

// 모든 블럭에 대해 탐색하면서 그룹을 묶음
// 그룹 내 블럭이 4개 이상이라면 빈 공간으로 처리
// 빈 공간으로 처리하는 행위를 수행했을 경우 true 반환
bool BFS() {
	bool ret = false;

	memset(chk, 0, sizeof(chk));
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (chk[i][j] || a[i][j] == '.') continue;
		chk[i][j] = true;
		queue<ii> q;
		q.push({ i,j });

		int cnt = 0;
		vii xy;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second; q.pop();
			xy.push_back({ x,y });
			++cnt;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (OOB(nx, ny)) continue;
				if (chk[nx][ny] || a[x][y] != a[nx][ny]) continue;
				chk[nx][ny] = true;
				q.push({ nx,ny });
			}
		}

		// 그룹 내 블럭 수가 4개 이상인 경우 -> 모두 빈 공간으로 만들기
		if (cnt >= 4) {
			ret = true;
			for (auto& cur : xy) {
				a[cur.first][cur.second] = '.';
			}
		}
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> a[i][j];
	}

	int ret = 0;
	while (BFS()) {
		++ret;
		for (int i = 0; i < 6; ++i) {
			base[i] = -1;
			bool flag = false;
			for (int j = 11; j >= 0; --j) {
				if (!flag && a[j][i] == '.') {
					base[i] = j + 1;
					flag = true;
				}

				// 빈 공간을 이미 만났고(base[i]가 갱신된 상태)
				// 허공에 있는 블럭을 발견한 경우
				if (flag && a[j][i] != '.') {
					a[base[i] - 1][i] = a[j][i];
					a[j][i] = '.';
					--base[i];
				}
			}
		}
	}
	
	cout << ret << '\n';

	return 0;
}