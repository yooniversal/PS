//3190
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int x, y, dir;
	char state; //Head, Tail, None
	P(int a, int b, int c, char d) : x(a), y(b), dir(c), state(d) {}
};

int n;
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
char a[101][101];
bool chk[101][101];
queue <pair<int, char>> turn;
deque<P> snake;

bool OOB(int x, int y) {
	if (x <= 0 || x > n || y <= 0 || y > n) return true;
	return false;
}

int solve() {
	int time = 0;
	//�Ӹ�, ������ ���� ����
	//�Ӹ��� ���̳� ���� �ε����� ��
	//����� ������ -> ���ο� �ڸ��� ���� ��ü, ���� ���� ���Ϳ� �ֱ�
	P head(1, 1, 0, 'H');
	P tail(-1, -1, -1, 'T');
	auto cur = turn.front();
	while (1) {
		/*printf("hx:%d hy:%d hd:%d t:%d\n", head.x, head.y, head.dir, time);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (chk[i][j]) {
					if (i == tail.x && j == tail.y) cout << 'T';
					else cout << 'B';
				}
				else {
					if (i == head.x && j == head.y) cout << 'H';
					else cout << a[i][j];
				}
			}
			cout << '\n';
		}
		cout << '\n';*/

		++time;
		//�Ӹ� �̵�
		//����� ������ ��
		int hd = head.dir;
		int hnx = head.x + dx[hd], hny = head.y + dy[hd];
		if (a[hnx][hny] == 'A') {
			a[hnx][hny] = '.';
			if (tail.x != -1) {
				snake.push_back(P(head.x, head.y, hd, 'N'));
				chk[head.x][head.y] = true;
			}
			else {
				tail.x = head.x;
				tail.y = head.y;
				tail.dir = hd;
				chk[tail.x][tail.y] = true;
			}
			head.x = hnx; head.y = hny;
		}
		//���� �Ϻ� Ȥ�� ���� ������ ��
		else if (chk[hnx][hny] || OOB(hnx, hny)) {
			return time;
		}
		//�ƹ� �͵� �ȸ����� ��
		else if(a[hnx][hny] == '.') {
			head.x = hnx; head.y = hny;
			//���� ������Ʈ
			for (int i = 0; i < snake.size(); ++i) {
				int dir = snake[i].dir;
				int nx = snake[i].x + dx[dir], ny = snake[i].y + dy[dir];
				chk[nx][ny] = true;
				snake[i].x = nx;
				snake[i].y = ny;
				if (a[nx][ny] == 'L') {
					if (snake[i].dir - 1 < 0) snake[i].dir = 3;
					else snake[i].dir -= 1;
				}
				else if (a[nx][ny] == 'D') {
					snake[i].dir = (dir + 1) % 4;
				}
			}
			//���� ������Ʈ
			if (tail.x != -1) {
				chk[tail.x][tail.y] = false;
				tail.x += dx[tail.dir]; tail.y += dy[tail.dir];
				chk[tail.x][tail.y] = true;
				if (a[tail.x][tail.y] == 'L') {
					if (tail.dir - 1 < 0) tail.dir = 3;
					else tail.dir -= 1;
					a[tail.x][tail.y] = '.';
				}
				else if (a[tail.x][tail.y] == 'D') {
					tail.dir = (tail.dir + 1) % 4;
					a[tail.x][tail.y] = '.';
				}
			}
		}

		//�Ӹ� ȸ��
		if (cur.first == time) {
			if (cur.second == 'L') {
				if (head.dir - 1 < 0) head.dir = 3;
				else head.dir -= 1;
				if(tail.x != -1) a[head.x][head.y] = 'L';
			}
			else if (cur.second == 'D') {
				head.dir = (head.dir + 1) % 4;
				if (tail.x != -1) a[head.x][head.y] = 'D';
			}
			turn.pop();
			if (!turn.empty()) cur = turn.front();
			else cur = { INF, 'F' };
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 101; ++j)
			a[i][j] = '.';

	int k; cin >> n >> k;
	while (k--) {
		int r, c; cin >> r >> c;
		a[r][c] = 'A';
	}
	int l; cin >> l;
	while (l--) {
		int t; char dir; cin >> t >> dir;
		turn.push({ t, dir });
	}

	cout << solve();

	return 0;
}