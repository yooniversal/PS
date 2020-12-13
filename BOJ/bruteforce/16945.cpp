//16945
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1005, INF = 1000000001, MOD = 1234567;

int num[10], ret = INF;
int t[10];
bool chk[10];
vi tmp;

bool check() {
	int lead = t[0] + t[4] + t[8];
	if (lead != t[2] + t[4] + t[6]) return false;
	int sum = 0;
	for (int i = 0; i < 3; ++i) sum += t[i];
	if (lead != sum) return false;
	sum = 0;
	for (int i = 3; i < 6; ++i) sum += t[i];
	if (lead != sum) return false;
	sum = 0;
	for (int i = 6; i < 9; ++i) sum += t[i];
	if (lead != sum) return false;
	sum = 0;
	for (int i = 0; i < 9; i += 3) sum += t[i];
	if (lead != sum) return false;
	sum = 0;
	for (int i = 1; i < 9; i += 3) sum += t[i];
	if (lead != sum) return false;
	sum = 0;
	for (int i = 2; i < 9; i += 3) sum += t[i];
	if (lead != sum) return false;
	return true;
}

void DFS(int cur, int cnt) {
	if (cur == 9) {
		if (!check()) return;
		ret = min(ret, cnt);
		return;
	}

	for (int i = 1; i <= 9; ++i) {
		if (chk[i]) continue;
		chk[i] = true;
		t[cur] = i;
		DFS(cur + 1, cnt + abs(tmp[cur] - i));
		t[cur] = 0;
		chk[i] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	for (int i = 0; i < 9; ++i) {
		int x; cin >> x;
		tmp.push_back(x);
	}
	
	DFS(0, 0);
	cout << ret << '\n';

	return 0;
}