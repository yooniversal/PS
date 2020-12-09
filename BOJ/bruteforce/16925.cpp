//16925
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

struct P {
	int n;
	string s;

	bool operator<(P& a) {
		return s.size() < a.s.size();
	}
};

int n;
char ret[201];
vector<P> a;
string target;

void DFS(int p) {
	if (p == 2 * n - 2) {
		cout << target << '\n';
		for (int i = 0; i < 2 * n - 2; ++i) cout << ret[i];
		cout << '\n';
		exit(0);
	}

	int len = a[p].s.size();
	vi edit[4];
	bool flag = true;
	//p번 접두사, p+1번 접미사
	for (int i = 0; i < len; ++i)
		if (target[i] == '+') {
			target[i] = a[p].s[i];
			edit[0].push_back(i);
		}
		else if (target[i] != a[p].s[i]) {
			flag = false;
			for (int e : edit[0]) target[e] = '+';
			edit[0].clear();
			break;
		}
	for (int i = 0; i < len; ++i)
		if (target[n-1-i] == '+') {
			target[n-1-i] = a[p+1].s[len-1-i];
			edit[1].push_back(n-1-i);
		}
		else if (target[n-1-i] != a[p+1].s[len-1-i]) {
			flag = false;
			for (int e : edit[1]) target[e] = '+';
			edit[1].clear();
			break;
		}
	if (flag) {
		ret[a[p].n] = 'P';
		ret[a[p + 1].n] = 'S';
		DFS(p + 2);
		ret[a[p].n] = '-';
		ret[a[p + 1].n] = '-';
	}
	for (int e : edit[0]) target[e] = '+';
	for (int e : edit[1]) target[e] = '+';
	edit[0].clear(); edit[1].clear();

	flag = true;
	//p번 접미사, p+1번 접두사
	for (int i = 0; i < len; ++i)
		if (target[i] == '+') {
			target[i] = a[p+1].s[i];
			edit[2].push_back(i);
		}
		else if (target[i] != a[p+1].s[i]) {
			flag = false;
			for (int e : edit[2]) target[e] = '+';
			edit[2].clear();
			break;
		}
	for (int i = 0; i < len; ++i)
		if (target[n-1-i] == '+') {
			target[n-1-i] = a[p].s[len-1-i];
			edit[3].push_back(n-1-i);
		}
		else if (target[n-1-i] != a[p].s[len-1-i]) {
			flag = false;
			for (int e : edit[3]) target[e] = '+';
			edit[3].clear();
			break;
		}
	if (flag) {
		ret[a[p].n] = 'S';
		ret[a[p + 1].n] = 'P';
		DFS(p + 2);
		ret[a[p].n] = '-';
		ret[a[p + 1].n] = '-';
	}
	for (int e : edit[2]) target[e] = '+';
	for (int e : edit[3]) target[e] = '+';
	edit[2].clear(); edit[3].clear();
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	target.resize(n, '+');
	for (int i = 0; i < 2*n-2; ++i) {
		string s; cin >> s;
		a.push_back({ i, s });
	}
	sort(a.begin(), a.end());

	DFS(0);

	return 0;
}