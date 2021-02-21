//1963
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 200005, INF = 1000000001, MOD = 9901;

struct P {
	string cur;
	int cnt;
};

bool prime[10000], chk[10000];
int dx[] = { 1000,100,10,1,-1000,-100,-10,-1 };

void eratosthenes() {
	memset(prime, true, sizeof(prime));
	int SN = sqrt(10000);
	for (int i = 2; i <= SN; i++) {
		if (!prime[i]) continue;
		for (int j = i + i; j < 10000; j += i)
			prime[j] = false;
	}
	prime[1] = false;
}

int BFS(string& a, string& b) {
	queue<P> q;
	q.push({ a, 0 });
	chk[stoi(a)] = true;
	while (!q.empty()) {
		string cur = q.front().cur;
		int cnt = q.front().cnt; q.pop();
		if (cur == b) return cnt;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j <= 9; ++j) {
				if (i == 0 && j == 0) continue;
				string next = cur;
				next[i] = j + '0';
				if (chk[stoi(next)] || !prime[stoi(next)]) continue;
				chk[stoi(next)] = true;
				q.push({ next, cnt + 1 });
			}
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	eratosthenes();
	int t; cin >> t;
	while (t--) {
		memset(chk, 0, sizeof(chk));
		string a, b; cin >> a >> b;
		int ret = BFS(a, b);
		if (ret == -1) cout << "Impossible\n";
		else cout << ret << '\n';
	}

	return 0;
}