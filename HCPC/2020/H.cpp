#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10000001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

//H번인가 풀다말았는데
//DP말고 BFS로 풀 수 있을듯
//거의 B번이랑 같은 수준인거 같은데 너무 아쉽다
//BFS로 안풀리면..
//공부할게 생겼으니 개꿀^^

//TC 1
/*
input :
14
5 8
2 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0
0 0 0 1 1 1 0 1
1 0 1 0 0 0 3 1
0 0 0 0 0 0 0 1

output :
11
*/

struct P {
	int x, y, d, dcnt, cnt;
};

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n, h, w, sx, sy, ex, ey;
int a[21][21];
int chk[21][21][21][21];

bool OOB(int x, int y) {
	if (x < 0 || x >= h || y < 0 || y >= w) return true;
	return false;
}

int BFS() {
	queue<P> q;
	q.push({ sx, sy, 5, 0, 0 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, d = q.front().d, dcnt = q.front().dcnt;
		int cnt = q.front().cnt; q.pop();
		//printf("x:%d y:%d d:%d dcnt:%d cnt:%d\n", x, y, d, dcnt, cnt);
		if (cnt > n) continue;
		if (x == ex && y == ey) return cnt;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (OOB(nx, ny)) continue;
			if (a[nx][ny] == 1) continue;
			//printf("nx:%d ny:%d chk:%d dcnt:%d\n", nx, ny, chk[x][y][nx][ny], dcnt);
			if (chk[x][y][nx][ny] <= dcnt) continue;
			//cout << "**\n";
			chk[x][y][nx][ny] = dcnt;
			if (d == i) {
				if (dcnt >= 2) continue;
				q.push({ nx,ny,d,dcnt + 1, cnt + 1 });
			}
			else {
				q.push({ nx,ny,i,1, cnt + 1 });
			}
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> h >> w;
	
	for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) for(int k=0; k<h; ++k) for(int f=0; f<w; ++f) chk[i][j][k][f]= 3;

	for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
		cin >> a[i][j];
		if (a[i][j] == 2) {
			sx = i; sy = j;
		}
		else if (a[i][j] == 3) {
			ex = i; ey = j;
		}
	}
	cout << BFS();

	return 0;
}