//16986
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 9001, INF = 1000000001, MOD = 1000000007;

int n, k;
int rsp[10][10], win[4];
int K[20], M[20];
bool used[10];

void DFS(int l, int r, int kp, int mp, int cnt) {
	if (win[1] >= k) {
		cout << 1 << '\n';
		exit(0);
	}
	if (win[2] == k || win[3] == k) return;
	if (kp >= 20 || mp >= 20 || cnt == n) return;

	int next = 6 - l - r;
	if (l > r) swap(l, r);

	if (r == 2) {
		if (l == 1) {
			for (int i = 1; i <= n; ++i) {
				if (used[i]) continue;
				if (rsp[i][K[kp]] != 2) {
					++win[r], used[i] = true;
					DFS(r, next, kp + 1, mp, cnt + 1);
					--win[r], used[i] = false;
				}
				else {
					++win[l], used[i] = true;
					DFS(l, next, kp + 1, mp, cnt + 1);
					--win[l], used[i] = false;
				}
			}
		}
	}
	else if(r == 3){
		if (l == 1) {
			for (int i = 1; i <= n; ++i) {
				if (used[i]) continue;
				if (rsp[i][M[mp]] != 2) {
					++win[r], used[i] = true;
					DFS(r, next, kp, mp + 1, cnt + 1);
					--win[r], used[i] = false;
				}
				else {
					++win[l], used[i] = true;
					DFS(l, next, kp, mp + 1, cnt + 1);
					--win[l], used[i] = false;
				}
			}
		}
		else if(l == 2){
			int winner = rsp[K[kp]][M[mp]] == 2 ? 2 : 3;
			++win[winner];
			DFS(winner, next, kp + 1, mp + 1, cnt);
			--win[winner];
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> rsp[i][j];
	for (int i = 0; i < 20; ++i) cin >> K[i];
	for (int i = 0; i < 20; ++i) cin >> M[i];

	DFS(1, 2, 0, 0, 0);

	cout << 0 << '\n';

	return 0;
}