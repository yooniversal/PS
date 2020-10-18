//2933
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

char a[105][105];
int uni[105][105];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int r, c;
vi stick;

bool OOB(int x, int y) {
	if (x <= 0 || x > r || y <= 0 || y > c) return true;
	return false;
}

void DFS(int x, int y, int n) {
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (OOB(nx, ny)) continue;
		if (a[nx][ny] == '.') continue;
		if (uni[nx][ny]) continue;
		uni[nx][ny] = n;
		DFS(nx, ny, n);
	}
}

//떨어져야 하는 클러스터가 있다면 위치도 같이 변경
void makeUnion() {
	//초기화
	memset(uni, 0, sizeof(uni));

	//집합별로 번호 붙이기
	int cnt = 0;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j) {
			if (a[i][j] == 'x') {
				if (uni[i][j]) continue;
				uni[i][j] = ++cnt;
				DFS(i, j, cnt);
			}
		}

	//각 집합별 바닥 미네랄이 얼마나 떠있는지 확인
	int boundOfUnion[10001];
	fill(boundOfUnion, boundOfUnion + cnt+1, INF);
	for (int C = 1; C <= c; ++C) {
		for (int U = 1; U <= cnt; ++U) {
			for (int R = r; R >= 1; --R) {
				if (a[R][C] == '.') continue;
				if (uni[R][C] != U) continue;
				int diff = 0;
				for (int toR = R + 1; toR <= r; ++toR) {
					if (a[toR][C] == '.') {
						if (toR == r) diff = toR - R;
						continue;
					}
					if (uni[toR][C] == U) continue;
					diff = (toR - 1) - R;
					break;
				}
				boundOfUnion[U] = min(boundOfUnion[U], diff);
				break;
			}
		}
	}

	for (int C = 1; C <= c; ++C) {
		for (int R = r; R >= 1; --R) {
			if (a[R][C] == '.') continue;
			int diff = boundOfUnion[uni[R][C]];
			a[R][C] = '.';
			a[R + diff][C] = 'x';
		}
	}
}

//turn 0:왼쪽->오른쪽 1:오른쪽->왼쪽
void solve(int row, int turn) {
	//막대기 던지기
	if (turn == 0) {
		for(int i=1; i<=c; ++i)
			if (a[row][i] == 'x') {
				a[row][i] = '.';
				break;
			}
	}
	else {
		for (int i = c; i >= 1; --i)
			if (a[row][i] == 'x') {
				a[row][i] = '.';
				break;
			}
	}

	makeUnion();
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c;
	for (int i = 1; i <= r; ++i) {
		string s; cin >> s;
		for (int j = 1; j <= c; ++j) {
			a[i][j] = s[j-1];
		}
	}
	int n; cin >> n;
	stick.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> stick[i];
		stick[i] = (r + 1) - stick[i];
	}
	for (int i = 0; i < n; ++i) solve(stick[i], i % 2);
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j)
			cout << a[i][j];
		cout << '\n';
	}

	return 0;
}