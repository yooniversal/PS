//1017

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
#define INF 987654321
#define MAX 2020
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

vi num[MAX];
bool chk[MAX];
int from[MAX];
int prime[MAX];
int n, m;

void PRIME() {
	for (int i = 1; i < MAX; i++)
		prime[i] = i;

	for (int i = 2; i <= sqrt(MAX); i++) {
		if (prime[i] == 0) continue;
		for (int j = i + i; j <= MAX; j += i) {
			prime[j] = 0;
		}
	}
}

bool dfs(int cur) {
	for (auto& next : num[cur]) {
		if (chk[next]) continue;
		chk[next] = true;

		if (from[next] == 0 || dfs(from[next])) {
			from[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	PRIME();

	//input
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i!=j && prime[arr[i] + arr[j]])
				num[arr[i]].push_back(arr[j]);
		}
	}

	vi ret;
	for (int t = 0; t < num[arr[0]].size(); t++) {
		fill(from, from + MAX, 0);
		int first = num[arr[0]][t];
		from[first] = arr[0];
		from[arr[0]] = first;

		int cnt = 2;
		for (int i = 1; i < n; i++) {
			fill(chk, chk + MAX, false);
			if (arr[i] == first) continue;
			chk[arr[0]] = true;
			chk[first] = true;
			if (dfs(arr[i])) cnt++;
		}
		if (cnt == n) ret.push_back(first);
	}

	sort(ret.begin(), ret.end());
	if (ret.empty()) cout << "-1";
	else
		for (auto& a : ret) cout << a << " ";

    return 0;
}