//1958
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007
#define MAX 50001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int d[105][105][105];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	for (int i = 0; i < s1.size(); ++i)
		for (int j = 0; j < s2.size(); ++j)
			for (int k = 0; k < s3.size(); ++k)
				if (s1[i] == s2[j] && s2[j] == s3[k]) d[i + 1][j + 1][k + 1] = d[i][j][k] + 1;
				else d[i + 1][j + 1][k + 1] = max(d[i][j + 1][k + 1], max(d[i + 1][j][k + 1], d[i + 1][j + 1][k]));
	cout << d[s1.size()][s2.size()][s3.size()];

	return 0;
}