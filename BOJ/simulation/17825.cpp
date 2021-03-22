//17825
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int adj[33][2] = {
	{1,-1}, {2,-1}, {3,-1}, {4,-1}, {5,-1},
	{13,6}, {7,-1}, {8,-1}, {9,-1}, {10,-1},
	{11,-1}, {12,-1}, {32,-1}, {14,-1}, {15,-1},
	{16,-1}, {17,-1}, {20,18}, {19,-1}, {9,-1},
	{21,-1}, {22,-1}, {23,-1}, {24,-1}, {28,25},
	{26,-1}, {27,-1}, {9,-1}, {29,-1}, {30,-1},
	{31,-1}, {12,-1}, {-1,-1}
};

int score[33] = { 
	0,2,4,6,8,
	10,13,16,19,25,
	30,35,40,12,14,
	16,18,20,22,24,
	22,24,26,28,30,
	28,27,26,32,34,
	36,38,0 };
int dice[10], ret;

void solve(vi cur, int turn, int cnt) {
	if (turn == 10) {
		ret = max(ret, cnt);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (cur[i] == 32) continue; // 도착한 말은 패스
		vi tmp = cur;
		int& next = tmp[i];
		for (int j = 0; j < dice[turn]; ++j) {
			if (j == 0) next = adj[next][1] == -1 ? adj[next][0] : adj[next][1];
			else next = adj[next][0];
			if (next == 32) break;
		}

		// 같은 위치면 패스
		bool flag = false;
		if (next != 32) {
			for (int j = 0; j < 4; ++j) {
				if (i == j || tmp[j] == 0 || tmp[j] == 32) continue;
				if (next == tmp[j]) {
					flag = true;
					break;
				}
			}
		}
		if (flag) continue;

		int add = score[next];
		solve(tmp, turn + 1, cnt + add);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	for (int i = 0; i < 10; ++i) cin >> dice[i];
	vi cur(4, 0);
	solve(cur, 0, 0);
	cout << ret << '\n';

	return 0;
}