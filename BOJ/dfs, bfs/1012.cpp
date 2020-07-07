//1012

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int arr[51][51], chk[51][51];
int m, n, k, ans;

void dfs(int x, int y) {
	chk[x][y] = 1;

	//종료 조건
	if (x < 0 || x > n - 1 || y < 0 || y > m - 1) return;
	else {
		if (arr[x + 1][y] == 0 && arr[x - 1][y] == 0 && arr[x][y - 1] == 0 && arr[x][y + 1] == 0)
			return;
		else {
			if (arr[x + 1][y] == 1 && chk[x+1][y] == 0) dfs(x + 1, y);
			if (arr[x - 1][y] == 1 && chk[x-1][y] == 0) dfs(x - 1, y);
			if (arr[x][y - 1] == 1 && chk[x][y-1] == 0) dfs(x, y - 1);
			if (arr[x][y + 1] == 1 && chk[x][y+1] == 0) dfs(x, y + 1);
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, x, y;

	cin >> t;

	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(chk, 0, sizeof(chk));
		ans = 0;

		//좌표 입력
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}

		//위치마다 탐색 진행
		//체크한 위치는 탐색하지 않음
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if (arr[i][j] == 1 && chk[i][j] == 0) {
					dfs(i, j);
					ans++;
				}

		cout << ans << "\n";
	}

	return 0;
}