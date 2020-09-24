//2529
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 101
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool chk[10];
string op, s;
vector<string> ret;
int n;

void dfs(int idx, char oper, int prev) {
	if (idx == n+1) {
		ret.push_back(s);
		return;
	}

	for (int i = 0; i <= 9; ++i) {
		if (chk[i]) continue;
		if (oper == '<' && prev >= i) continue;
		if (oper == '>' && prev <= i) continue;
		chk[i] = true;
		s += i + '0';
		dfs(idx + 1, op[s.size()-1], i);
		s.pop_back();
		chk[i] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		char oper; cin >> oper;
		op += oper;
	}

	dfs(0, 'A', -1);

	sort(ret.begin(), ret.end());
	cout << ret[ret.size() - 1] << '\n' << ret[0];

	return 0;
}