//15723
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[27][27];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 27; ++i)
		for (int j = 0; j < 27; ++j)
			if (i != j)
				d[i][j] = INF;

	int n; cin >> n;
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		string s; getline(cin, s);
		d[s[0] - 'a'][s[5] - 'a'] = 1;
	}

	for (int k = 0; k < 27; ++k)
		for (int i = 0; i < 27; ++i)
			for (int j = 0; j < 27; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	int t; cin >> t;
	cin.ignore();
	while (t--) {
		string s; getline(cin, s);
		if (d[s[0] - 'a'][s[5] - 'a'] == INF) cout << "F\n";
		else cout << "T\n";
	}

	return 0;
}