//16939
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2501
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool fin(const vvi& cube) {
	for (int i = 0; i < 6; ++i) for (int j = 1; j < 4; ++j) {
		if (cube[i][0] != cube[i][j]) return false;
	}
	return true;
}

bool up1(const vvi& cube) {
	vvi tmp = cube;
	swap(tmp[5][1], tmp[0][0]);
	swap(tmp[5][3], tmp[0][2]);
	swap(tmp[0][0], tmp[1][0]);
	swap(tmp[0][2], tmp[1][2]);
	swap(tmp[1][0], tmp[2][0]);
	swap(tmp[1][2], tmp[2][2]);
	if (fin(tmp)) return true;

	tmp = cube;
	swap(tmp[5][0], tmp[0][1]);
	swap(tmp[5][2], tmp[0][3]);
	swap(tmp[0][1], tmp[1][1]);
	swap(tmp[0][3], tmp[1][3]);
	swap(tmp[1][1], tmp[2][1]);
	swap(tmp[1][3], tmp[2][3]);
	if (fin(tmp)) return true;
	return false;
}

bool up2(const vvi& cube) {
	vvi tmp = cube;
	swap(tmp[5][0], tmp[4][0]);
	swap(tmp[5][1], tmp[4][1]);
	swap(tmp[4][0], tmp[1][0]);
	swap(tmp[4][1], tmp[1][1]);
	swap(tmp[1][0], tmp[3][0]);
	swap(tmp[1][1], tmp[3][1]);
	if (fin(tmp)) return true;

	tmp = cube;
	swap(tmp[5][2], tmp[4][2]);
	swap(tmp[5][3], tmp[4][3]);
	swap(tmp[4][2], tmp[1][2]);
	swap(tmp[4][3], tmp[1][3]);
	swap(tmp[1][2], tmp[3][2]);
	swap(tmp[1][3], tmp[3][3]);
	if (fin(tmp)) return true;
	return false;
}

bool down1(const vvi& cube) {
	vvi tmp = cube;
	swap(tmp[2][0], tmp[1][0]);
	swap(tmp[2][2], tmp[1][2]);
	swap(tmp[1][0], tmp[0][0]);
	swap(tmp[1][2], tmp[0][2]);
	swap(tmp[0][0], tmp[5][1]);
	swap(tmp[0][2], tmp[5][3]);
	if (fin(tmp)) return true;

	tmp = cube;
	swap(tmp[2][1], tmp[1][1]);
	swap(tmp[2][3], tmp[1][3]);
	swap(tmp[1][1], tmp[0][1]);
	swap(tmp[1][3], tmp[0][3]);
	swap(tmp[0][1], tmp[5][0]);
	swap(tmp[0][3], tmp[5][2]);
	if (fin(tmp)) return true;
	return false;
}

bool down2(const vvi& cube) {
	vvi tmp = cube;
	swap(tmp[3][0], tmp[1][0]);
	swap(tmp[3][1], tmp[1][1]);
	swap(tmp[1][0], tmp[4][0]);
	swap(tmp[1][1], tmp[4][1]);
	swap(tmp[4][0], tmp[5][0]);
	swap(tmp[4][1], tmp[5][1]);
	if (fin(tmp)) return true;

	tmp = cube;
	swap(tmp[3][2], tmp[1][2]);
	swap(tmp[3][3], tmp[1][3]);
	swap(tmp[1][2], tmp[4][2]);
	swap(tmp[1][3], tmp[4][3]);
	swap(tmp[4][2], tmp[5][2]);
	swap(tmp[4][3], tmp[5][3]);
	if (fin(tmp)) return true;
	return false;
}

bool left(const vvi& cube) {
	vvi tmp = cube;
	swap(tmp[2][0], tmp[3][1]);
	swap(tmp[2][1], tmp[3][3]);
	swap(tmp[3][1], tmp[0][2]);
	swap(tmp[3][3], tmp[0][3]);
	swap(tmp[0][2], tmp[4][0]);
	swap(tmp[0][3], tmp[4][2]);
	if (fin(tmp)) return true;

	tmp = cube;
	swap(tmp[2][2], tmp[3][0]);
	swap(tmp[2][3], tmp[3][2]);
	swap(tmp[3][0], tmp[0][0]);
	swap(tmp[3][2], tmp[0][1]);
	swap(tmp[0][0], tmp[4][1]);
	swap(tmp[0][1], tmp[4][3]);
	if (fin(tmp)) return true;
	return false;
}

bool right(const vvi& cube) {
	vvi tmp = cube;
	swap(tmp[4][0], tmp[0][2]);
	swap(tmp[4][2], tmp[0][3]);
	swap(tmp[0][2], tmp[3][1]);
	swap(tmp[0][3], tmp[3][3]);
	swap(tmp[3][1], tmp[2][0]);
	swap(tmp[3][3], tmp[2][1]);
	if (fin(tmp)) return true;

	tmp = cube;
	swap(tmp[4][1], tmp[0][0]);
	swap(tmp[4][3], tmp[0][1]);
	swap(tmp[0][0], tmp[3][0]);
	swap(tmp[0][1], tmp[3][2]);
	swap(tmp[3][0], tmp[2][2]);
	swap(tmp[3][2], tmp[2][3]);
	if (fin(tmp)) return true;
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vvi cube(6, vi(4, 0));
	for (int i = 0; i < 6; ++i) for (int j = 0; j < 4; ++j) {
		cin >> cube[i][j];
	}

	/*printf("  %d%d\n  %d%d\n", cube[0][0], cube[0][1], cube[0][2], cube[0][3]);
	int x[] = { 3,3,1,1,4,4,5,5 }, y[] = { 0,1,0,1,0,1,0,1 };
	for (int i = 0; i < 8; ++i) cout << cube[x[i]][y[i]];
	cout << '\n';
	int y2[] = { 2,3,2,3,2,3,2,3 };
	for (int i = 0; i < 8; ++i) cout << cube[x[i]][y2[i]];
	cout << '\n';
	printf("  %d%d\n  %d%d\n", cube[2][0], cube[2][1], cube[2][2], cube[2][3]);
	cout << '\n';*/

	if (up1(cube) || up2(cube) || down1(cube) || down2(cube) || left(cube) || right(cube)) cout << 1;
	else cout << 0;

	return 0;
}