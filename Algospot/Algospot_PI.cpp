#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 1000000001
#define MAX 10005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int dp[MAX];
string S;

int level(int s, int e) {
	string M = S.substr(s, e-s+1);

	bool same = true;
	for (int i = 1; i < M.size(); i++)
		if (M[0] != M[i]) same = false;
	if (same) return 1;

	bool progress = true;
	for (int i = 0; i < M.size()-1; i++)
		if (M[i+1] - M[i] != M[1] - M[0]) progress = false;
	if (progress && abs(M[1] - M[0]) == 1) return 2;

	bool alter = true;
	for (int i = 0; i < M.size(); i++)
		if (M[i] != M[i % 2]) alter = false;
	if (alter) return 4;
	if (progress) return 5;
	return 10;
}

int f(int begin) {
	if (begin >= S.size()) return 0;

	int& ret = dp[begin];
	if (ret != -1) return ret;

	ret = INF;
	for (int L = 3; L <= 5; L++)
		if(begin+L <= S.size())
			ret = min(ret, f(begin + L) + level(begin, begin + L - 1));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> S;
		cout << f(0) << '\n';
	}

	return 0;
}