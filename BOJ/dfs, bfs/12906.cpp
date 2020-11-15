//12906
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct Hanoi {
	string s[3];
	int cnt;
};

Hanoi S;
map<vector<string>, bool> chk;

bool end(string& a, string& b, string& c) {
	for (int i = 0; i < a.size(); ++i)
		if (a[i] != 'A')
			return false;
	for (int i = 0; i < b.size(); ++i)
		if (b[i] != 'B')
			return false;
	for (int i = 0; i < c.size(); ++i)
		if (c[i] != 'C')
			return false;
	return true;
}

int BFS() {
	queue<Hanoi> q;
	q.push(S);
	chk[{S.s[0], S.s[1], S.s[2]}] = true;
	while (!q.empty()) {
		Hanoi cur = q.front(); q.pop();
		if (end(cur.s[0], cur.s[1], cur.s[2])) return cur.cnt;
		for (int i = 0; i < 3; ++i) {
			if (cur.s[i] == "") continue;
			for (int j = 0; j < 3; ++j) {
				if (i == j) continue;
				string now = cur.s[i], next = cur.s[j];
				next += now.back();
				now.pop_back();
				vector<string> t(3, "");
				t[i] = now, t[j] = next, t[3-i-j] = cur.s[3-i-j];
				if (chk[t]) continue;
				chk[t] = true;
				q.push({ t[0], t[1], t[2], cur.cnt + 1 });
			}
		}
	}
	return -1;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	if (n) cin >> S.s[0];
	else S.s[0] = "";
	cin >> n;
	if (n) cin >> S.s[1];
	else S.s[1] = "";
	cin >> n;
	if (n) cin >> S.s[2];
	else S.s[2] = "";

	cout << BFS();

	return 0;
}