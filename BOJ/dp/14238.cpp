//14238
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 10007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n, A, B, C;
bool cache[51][51][51][2][3];
char ans[51];

bool f(int cur, int b, int c, int pb, int pc) {
	if (cur == n) {
		if (b==0 && c==0) return true;
		return false;
	}
	if (cache[cur][b][c][pb][pc]) return false;
	cache[cur][b][c][pb][pc] = true;
	
	if (A) {
		ans[cur] = 'A'; A--;
		if (pb > 0 && pc > 0) {
			if (f(cur + 1, b, c, pb - 1, pc - 1)) return true;
		}
		else if (pb > 0) {
			if (f(cur + 1, b, c, pb - 1, pc)) return true;
		}
		else if (pc > 0) {
			if (f(cur + 1, b, c, pb, pc - 1)) return true;
		}
		else
			if (f(cur + 1, b, c, pb, pc)) return true;
		A++;
	}
	
	if (b) {
		ans[cur] = 'B';
		if (pb == 0) {
			if (pc > 0) {
				if (f(cur + 1, b-1, c, pb + 1, pc - 1)) return true;
			}
			else
				if (f(cur + 1, b-1, c, pb + 1, pc)) return true;
		}
	}

	if (c) {
		ans[cur] = 'C';
		if (pc == 0) {
			if (pb > 0) {
				if (f(cur + 1, b, c-1, pb - 1, pc + 2)) return true;
			}
			else
				if (f(cur + 1, b, c-1, pb, pc + 2)) return true;
		}
	}

	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	n = s.size();
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'A') ++A;
		else if (s[i] == 'B') ++B;
		else ++C;
	}

	if (f(0, B, C, 0, 0)) {
		for (int i = 0; i < n; ++i)
			printf("%c", ans[i]);
	}
	else {
		cout << -1;
	}

	return 0;
}