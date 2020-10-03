//2251
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct t {
	int a, b, c;
	t(int a, int b, int c) : a(a), b(b), c(c) {}
};

int a, b, c;
bool chk[205][205], rchk[205];
vi ret;

void bfs() {
	queue<t> q;
	q.push(t(0, 0, c));
	while (!q.empty()) {
		t cur = q.front(); q.pop();
		if (chk[cur.a][cur.b]) continue;
		chk[cur.a][cur.b] = true;
		if (cur.a == 0 && !rchk[cur.c]) {
			rchk[cur.c] = true;
			ret.push_back(cur.c);
		}

		if (c-cur.c - cur.a >= 0) q.push(t(0, cur.b, cur.a+cur.c));
		else q.push(t(cur.c + cur.a - c, cur.b, c));
		if (b - cur.b - cur.a >= 0) q.push(t(0, cur.a+cur.b, cur.c));
		else q.push(t(cur.a + cur.b - b, b, cur.c));

		if (c - cur.c - cur.b >= 0) q.push(t(cur.a, 0, cur.b + cur.c));
		else q.push(t(cur.a, cur.c + cur.b - c, c));
		if (a - cur.a - cur.b >= 0) q.push(t(cur.a + cur.b, 0, cur.c));
		else q.push(t(a, cur.a + cur.b - a, cur.c));

		if (a - cur.a - cur.c >= 0) q.push(t(cur.a + cur.c, cur.b, 0));
		else q.push(t(a, cur.b, cur.a + cur.c - a));
		if (b - cur.b - cur.c >= 0) q.push(t(cur.a, cur.b + cur.c, 0));
		else q.push(t(cur.a, b, cur.b + cur.c - b));
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b >> c;
	bfs();
	sort(ret.begin(), ret.end());
	for (int r : ret) cout << r << " ";

	return 0;
}