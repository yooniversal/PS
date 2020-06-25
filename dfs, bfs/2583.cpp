//2583

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int row, col, block;
long long cnt;
bool check[101][101], visit[101][101];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,1,-1 };
vector<long long> ans;

void getans(int y, int x) {

	//���� ����
	if (check[y][x] == true || visit[y][x] == true) return;

	visit[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny < 1 || ny > row || nx<1 || nx>col) continue;
		getans(ny, nx);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> row >> col >> block;

	//check�� �� ǥ��
	while (block--) {
		int sy, sx, ey, ex;
		cin >> sx >> sy >> ex >> ey;
		for (int y = row - sy; y > row - ey; y--)
			for (int x = sx+1; x <= ex; x++)
				check[y][x] = true;
	}

	//������ �� �ִ� ���� cnt�� üũ �� push
	//��Ÿ�� cnt �ʱ�ȭ
	for (int y = 1; y <= row; y++)
		for (int x = 1; x <= col; x++) {
			getans(y, x);
			if(cnt!=0)
				ans.push_back(cnt);
			cnt = 0;
		}

	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if(ans[i] != 0)
			cout << ans[i] << " ";
	}

	return 0;
}