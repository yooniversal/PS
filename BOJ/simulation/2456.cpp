//2456
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1000000007;

int score[3], num[3][4];

int who(int a, int b) {
	if (a == b) return a + 1;
	if (a == -1) {
		if (b == -1) return 0;
		if (b != 0) return who(0, b);
		return who(1, b);
	}
	if (b == -1) {
		if (a != 0) return who(0, a);
		return who(1, a);
	}
	if (num[a][3] > num[b][3]) return a + 1;
	if (num[a][3] < num[b][3]) return b + 1;
	if (num[a][2] > num[b][2]) return a + 1;
	if (num[a][2] < num[b][2]) return b + 1;
	return 0;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			int x; cin >> x;
			score[j] += x;
			num[j][x]++;
		}
	}

	int maxx = 0;
	for (int i = 0; i < 3; ++i) maxx = max(maxx, score[i]);

	int rank = -1;
	if (maxx == score[0]) {
		rank = 1;
		if (score[0] == score[1]) {
			rank = who(0, 1);
			if (score[1] == score[2]) {
				int tmp = who(1, 2);
				rank = who(rank - 1, tmp - 1);
			}
		}
		else if (score[0] == score[2]) {
			rank = who(0, 2);
		}
	}
	else if (maxx == score[1]) {
		rank = 2;
		if (score[1] == score[0]) {
			rank = who(0, 1);
			if (score[0] == score[2]) {
				int tmp = who(0, 2);
				rank = who(rank - 1, tmp - 1);
			}
		}
		else if (score[1] == score[2]) {
			rank = who(1, 2);
		}
	}
	else {
		rank = 3;
		if (score[2] == score[0]) {
			rank = who(0, 2);
			if (score[0] == score[1]) {
				int tmp = who(0, 1);
				rank = who(rank - 1, tmp - 1);
			}
		}
		else if (score[2] == score[1]) {
			rank = who(2, 1);
		}
	}

	cout << rank << ' ' << maxx << '\n';

	return 0;
}