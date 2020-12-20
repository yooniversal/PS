//1074
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int n, r, c, cnt, ret;

void DFS(int ux, int dx, int ly, int ry) {
	if (ux == dx && ly == ry) {
		if (ux == r && ly == c) {
			cout << cnt << '\n';
			exit(0);
		}
		cnt++;
		return;
	}

	if ((ux <= r && r <= (ux + dx) / 2) && (ly <= c && c <= (ly + ry) / 2)) DFS(ux, (ux + dx) / 2, ly, (ly + ry) / 2);
	else cnt += ((ux + dx) / 2 - ux + 1) * ((ux + dx) / 2 - ux + 1);
	if ((ux <= r && r <= (ux + dx) / 2) && ((ly + ry) / 2) + 1 <= c && c <= ry) DFS(ux, (ux + dx) / 2, (ly + ry) / 2 + 1, ry);
	else cnt += ((ux + dx) / 2 - ux + 1) * ((ux + dx) / 2 - ux + 1);
	if (((ux + dx) / 2 + 1 <= r && r <= dx) && (ly <= c && c <= (ly + ry) / 2)) DFS((ux + dx) / 2 + 1, dx, ly, (ly + ry) / 2);
	else cnt += (dx - ((ux + dx) / 2 + 1) + 1) * (dx - ((ux + dx) / 2 + 1) + 1);
	if (((ux + dx) / 2 + 1 <= r && r <= dx) && ((ly + ry) / 2) + 1 <= c && c <= ry) DFS((ux + dx) / 2 + 1, dx, (ly + ry) / 2 + 1, ry);
	else cnt += (dx - ((ux + dx) / 2 + 1) + 1) * (dx - ((ux + dx) / 2 + 1) + 1);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> r >> c;
	DFS(0, (1 << n) - 1, 0, (1 << n) - 1);

	return 0;
}