//15558
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int idx, line, cnt;
};

int n, k;
bool chk[2][100001];
string s[2];

int bfs() {
	queue<P> q;
	q.push({ 0, 0, 0 });
	while (!q.empty()) {
		P cur = q.front(); q.pop();
		if (cur.idx < 0) continue;
		if (cur.idx < cur.cnt) continue;
		if (cur.idx >= n) return 1;
		if (s[cur.line][cur.idx] == '0') continue;
		if (chk[cur.line][cur.idx]) continue;
		chk[cur.line][cur.idx] = true;
		int rev;
		if (cur.line == 0) rev = 1;
		else rev = 0;
		q.push({ cur.idx - 1, cur.line, cur.cnt+1 });
		q.push({ cur.idx + 1, cur.line, cur.cnt + 1 });
		q.push({ cur.idx + k, rev, cur.cnt + 1 });
	}
	return 0;
}
	

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	cin >> s[0] >> s[1];
	cout << bfs();

	return 0;
}