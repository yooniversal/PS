//16137
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int x, y, cnt;
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, m;
int a[11][11], chk[11][11];
bool ban[11][11];

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}

int turn(int cnt, int M) {
	while (cnt % M != 0) ++cnt;
	return cnt;
}

int BFS() {
	for (int i = 0; i < 11; ++i)
		for (int j = 0; j < 11; ++j)
			chk[i][j] = INF;

	int ret = INF;
	queue<P> q;
	q.push({ 0,0,0 });
	chk[0][0] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt; q.pop();
		if (x == n - 1 && y == n - 1) {
			ret = min(ret, cnt);
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] == 0) continue;
			//��
			if (a[nx][ny] == 1) {
				if (chk[nx][ny] <= cnt+1) continue;
				chk[nx][ny] = cnt+1;
				q.push({ nx, ny, cnt + 1 });
			}
			//���۱�
			else {
				if (a[x][y] != 1) continue; //�̹� ���۱��� �ǳԴٸ� �ٸ� ���۱��� �ǳ� �� ����
				int next = turn(cnt + 1, a[nx][ny]);
				if (chk[nx][ny] <= next) continue;
				chk[nx][ny] = next;
				q.push({ nx, ny, next });
			}
		}
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	
	//���۱� ��ġ �Ұ� ���� Ž��(���� ���� Ž��) => ���μ��� üũ
	bool cross[11][11][2] = { 0 };
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == 1) continue;
			for (int d = 0; d < 4; ++d) {
				int nx = i + dx[d], ny = j + dy[d];
				if (OOB(nx, ny)) continue;
				if (a[nx][ny] == 1) continue;
				//����
				if (d <= 1) {
					for (int nnx = i, nny = j; !OOB(nnx, nny) && a[nnx][nny] != 1; nnx+=dx[d], nny+=dy[d]) {
						cross[nnx][nny][0] = true;
					}
				}
				//����
				else {
					for (int nnx = i, nny = j; !OOB(nnx, nny) && a[nnx][nny] != 1; nnx+=dx[d], nny+=dy[d]) {
						cross[nnx][nny][1] = true;
					}
				}
			}
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] != 1)
				if (a[i][j] != 0 || (cross[i][j][0] && cross[i][j][1]))
					ban[i][j] = true;

	int ret = INF;
	ret = min(ret, BFS());
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] == 0 && !ban[i][j]) {
				a[i][j] = m;
				ret = min(ret, BFS());
				a[i][j] = 0;
			}
	cout << ret;

	return 0;
}