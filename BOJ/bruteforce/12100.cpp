//12100
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
int ret;

int getMAX(const vvi& a) {
	int ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ret = max(ret, a[i][j]);
	return ret;
}

//0:UP 1:DOWN 2:LEFT 3:RIGHT
void move(vvi& a, int dir) {
	if (dir == 0) {
		for (int col = 0; col < n; ++col) {
			int target = 0;
			for (int row = 1; row < n; ++row) {
				if (a[row][col]) {
					//0 이면
					if (!a[target][col]) {
						a[target][col] = a[row][col];
						a[row][col] = 0;
					}
					//같으면
					else if (a[target][col] == a[row][col]) {
						a[target++][col] += a[row][col];
						a[row][col] = 0;
					}
					//다르면
					else {
						a[++target][col] = a[row][col];
						if(target != row) a[row][col] = 0;
					}
				}
			}
		}
	}
	else if (dir == 1) {
		for (int col = 0; col < n; ++col) {
			int target = n-1;
			for (int row = n-2; row >= 0; --row) {
				if (a[row][col]) {
					//0 이면
					if (!a[target][col]) {
						a[target][col] = a[row][col];
						a[row][col] = 0;
					}
					//같으면
					else if (a[target][col] == a[row][col]) {
						a[target--][col] += a[row][col];
						a[row][col] = 0;
					}
					//다르면
					else {
						a[--target][col] = a[row][col];
						if (target != row) a[row][col] = 0;
					}
				}
			}
		}
	}
	else if (dir == 2) {
		for (int row = 0; row < n; ++row) {
			int target = 0;
			for (int col = 1; col < n; ++col) {
				if (a[row][col]) {
					//0 이면
					if (!a[row][target]) {
						a[row][target] = a[row][col];
						a[row][col] = 0;
					}
					//같으면
					else if (a[row][target] == a[row][col]) {
						a[row][target++] += a[row][col];
						a[row][col] = 0;
					}
					//다르면
					else {
						a[row][++target] = a[row][col];
						if (target != col) a[row][col] = 0;
					}
				}
			}
		}
	}
	else {
		for (int row = 0; row < n; ++row) {
			int target = n-1;
			for (int col = n-2; col >= 0; --col) {
				if (a[row][col]) {
					//0 이면
					if (!a[row][target]) {
						a[row][target] = a[row][col];
						a[row][col] = 0;
					}
					//같으면
					else if (a[row][target] == a[row][col]) {
						a[row][target--] += a[row][col];
						a[row][col] = 0;
					}
					//다르면
					else {
						a[row][--target] = a[row][col];
						if (target != col) a[row][col] = 0;
					}
				}
			}
		}
	}
}

void dfs(const vvi& a, int cnt) {
	if (cnt > 5) return;
	ret = max(ret, getMAX(a));

	for (int dir = 0; dir < 4; ++dir) {
		vvi tmp = a;
		move(tmp, dir);
		dfs(tmp, cnt + 1);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vvi board;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		vi tmp(n);
		for (int j = 0; j < n; ++j)
			cin >> tmp[j];
		board.push_back(tmp);
	}

	dfs(board, 0);

	cout << ret;

	return 0;
}