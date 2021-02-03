//1309
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 9901;

int cache[100001][3];
int n;

//현재 층, 현재 층에 존재하는 사자 열 정보 [없음, 1열, 2열]
int f(int cur, int col) {
	if (cur == n - 1) return 1;
	int& ret = cache[cur][col];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 3; ++i) {
		if (col && col == i) continue;
		ret = (ret + f(cur + 1, i)) % MOD;
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n;
	
	int ret = 0;
	for (int i = 0; i < 3; ++i) {
		ret = (ret + f(0, i)) % MOD;
	}
	cout << ret << '\n';

	return 0;
}