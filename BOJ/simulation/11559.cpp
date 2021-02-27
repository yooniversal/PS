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
int base[6]; // ���� ���� �ִ� ���̸� ����Ű�� �ε���
char a[12][6];
bool chk[12][6];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

// ��� ���� ���� Ž���ϸ鼭 �׷��� ����
// �׷� �� ���� 4�� �̻��̶�� �� �������� ó��
// �� �������� ó���ϴ� ������ �������� ��� true ��ȯ
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

		// �׷� �� �� ���� 4�� �̻��� ��� -> ��� �� �������� �����
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

				// �� ������ �̹� ������(base[i]�� ���ŵ� ����)
				// ����� �ִ� ���� �߰��� ���
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