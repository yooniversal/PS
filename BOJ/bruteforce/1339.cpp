//1339
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 101
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int a[27];
vi alpha;

int toi(string s) {
	int ret = 0;
	for (int i = 0; i < s.size(); ++i)
		ret = ret * 10 + a[s[i] - 'A'];
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(a, -1, sizeof(a));

	vector<string> S;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		S.push_back(s);
		for (int j = 0; j < s.size(); ++j)
			alpha.push_back(s[j] - 'A');
	}
	sort(alpha.begin(), alpha.end());
	alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());

	int cnt = 10-alpha.size();
	string p;
	for (int i = 0; i < alpha.size(); ++i)
		p += '0' + cnt++;

	ll ret = 0;
	do {
		ll tmp = 0;
		for (int i = 0; i < alpha.size(); ++i)
			a[alpha[i]] = p[i] - '0';
		
		for (int i = 0; i < S.size(); ++i)
			tmp += toi(S[i]);

		ret = max(ret, tmp);
	} while (next_permutation(p.begin(), p.end()));

	cout << ret;

	return 0;
}