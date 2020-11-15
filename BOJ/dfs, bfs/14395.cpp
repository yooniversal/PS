//14395
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

struct P {
	ll v;
	string s;
};

ll s, t;
map<ll, bool> chk;

void BFS() {
	queue<P> q;
	q.push({ s, "" });
	chk[s] = true;
	while (!q.empty()) {
		P cur = q.front(); q.pop();
		//cout << "v:" << cur.v << " s:" << cur.s << '\n';
		if (cur.v == t) {
			cout << cur.s;
			exit(0);
		}
		if (cur.v > 1000000000) continue;

		if (!chk[cur.v * cur.v]) {
			chk[cur.v * cur.v] = true;
			q.push({ cur.v * cur.v , cur.s + '*' });
		}

		if (!chk[cur.v + cur.v]) {
			chk[cur.v + cur.v] = true;
			q.push({ cur.v + cur.v , cur.s + '+' });
		}

		if (!chk[cur.v - cur.v]) {
			chk[cur.v - cur.v] = true;
			q.push({ cur.v - cur.v , cur.s + '-' });
		}

		if (cur.v <= 0) continue;
		if (!chk[cur.v / cur.v]) {
			chk[cur.v / cur.v] = true;
			q.push({ cur.v / cur.v , cur.s + '/' });
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s >> t;
	if (s == t) cout << 0;
	else {
		BFS();
		cout << -1;
	}

	return 0;
}