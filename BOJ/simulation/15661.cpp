//15661
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n;
int arr[21][21], ret = INF;
bool team[21];

int solve() {
	
	vi t1, t2;
	for (int i = 0; i < n; ++i) {
		if (team[i]) t1.emplace_back(i);
		else t2.emplace_back(i);
	}

	int sum = 0, sum2 = 0;
	for (int i = 0; i < t1.size()-1; ++i) {
		for (int j = i + 1; j < t1.size(); ++j) {
			sum += arr[t1[i]][t1[j]] + arr[t1[j]][t1[i]];
		}
	}

	for (int i = 0; i < t2.size() - 1; ++i) {
		for (int j = i + 1; j < t2.size(); ++j) {
			sum2 += arr[t2[i]][t2[j]] + arr[t2[j]][t2[i]];
		}
	}

	
	cout << "t1: ";
	for (int t : t1) cout << t << " ";
	cout << "/ t2: ";
	for (int t : t2) cout << t << " ";
	printf("/ sum:%d sum2:%d\n", sum, sum2);
	

	return abs(sum - sum2);
}

void select_member(int size, int cnt, int start) {
	if (cnt >= size) {

		ret = min(ret, solve());
		return;
	}

	for (int i = start; i < n; ++i) {
		if (team[i]) continue;
		team[i] = true;
		select_member(size, cnt + 1, i + 1);
		team[i] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	for (int i = 1; i <= n / 2; ++i) {
		select_member(i, 0, 0);
	}

	cout << ret << '\n';

	return 0;
}