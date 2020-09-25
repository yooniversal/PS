//14889
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 501
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int a[21][21];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	string team;
	for (int i = 0; i < n; ++i)
		if (i < n / 2) team += '0';
		else team += '1';

	int ret = INF;
	do {
		vi s, l; //start, link
		for (int i = 0; i < n; ++i)
			if (team[i] == '1') s.push_back(i);
			else l.push_back(i);
		
		int S = 0, L = 0;
		for (int i = 0; i < s.size() - 1; ++i)
			for (int j = i + 1; j < s.size(); ++j)
				S += a[s[i]][s[j]] + a[s[j]][s[i]];

		for (int i = 0; i < l.size() - 1; ++i)
			for (int j = i + 1; j < l.size(); ++j)
				L += a[l[i]][l[j]] + a[l[j]][l[i]];

		ret = min(ret, abs(S - L));

	} while (next_permutation(team.begin(), team.end()));

	cout << ret;

	return 0;
}