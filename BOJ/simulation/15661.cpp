//15661
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
int arr[21][21];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	string team;
	for (int i = 0; i < n; ++i)
		if (i < n / 2) team += '0';
		else team += '1';

	int ret = INF;
	do {
		vi a, b;
		for (int i = 0; i < team.size(); ++i) {
			if (team[i] == '1') a.push_back(i);
			else b.push_back(i);
		}

		int r1 = 0;
		for (int i = 0; i < a.size(); ++i)
			for (int j = i+1; j < a.size(); ++j)
				r1 += arr[a[i]][a[j]] + arr[a[j]][a[i]];

		int r2 = 0;
		for (int i = 0; i < b.size(); ++i)
			for (int j = i + 1; j < b.size(); ++j)
				r2 += arr[b[i]][b[j]] + arr[b[j]][b[i]];

		ret = min(ret, abs(r1 - r2));

	} while (next_permutation(team.begin(), team.end()));

	cout << ret;

	return 0;
}