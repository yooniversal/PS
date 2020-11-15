//2504
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 4005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

string s;
int ret;
bool chk[31];

//prev 0:() 1:[]
int DFS(int i, int prev) {
	if (chk[i]) return DFS(i + 1, prev);
	int ret = 0;
	chk[i] = true;
	if (s[i] == ')') {
		if (prev == 0) return 1;
		cout << 0;
		exit(0);
	}
	else if (s[i] == ']') {
		if (prev == 1) return 1;
		cout << 0;
		exit(0);
	}
	else if (s[i] == '(') {
		while (1) {
			int next = DFS(i + 1, 0);
			if (next == 1) break;
			ret += next;
		}
		ret = ret == 0 ? 1 : ret;
		return 2 * ret;
	}
	else {
		while (1) {
			int next = DFS(i + 1, 1);
			if (next == 1) break;
			ret += next;
		}
		ret = ret == 0 ? 1 : ret;
		return 3 * ret;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		if (chk[i]) continue;
		ret += DFS(i, -1);
	}

	cout << ret;

	return 0;
}