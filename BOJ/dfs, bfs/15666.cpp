//15666

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
#define MAX 20001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool chk[65];
int n, m, cur;
vi ret, arr;

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << ret[i] << " ";
		cout << '\n';
		return;
	}

	int prev = 0; //같은 자리에 오는 숫자 중복 제거
	for (int i = 0; i < arr.size(); i++) {
		if (chk[i] || prev == arr[i] || cur > arr[i]) continue;
		cur = arr[i];
		prev = arr[i];
		chk[i] = true;
		ret.push_back(arr[i]);
		dfs(cnt+1);
		ret.pop_back();
		cur = 0;
		chk[i] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	vi tmp(n);
	for (int i = 0; i < n; i++) cin >> tmp[i];
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	
	for (int i = 0; i < tmp.size(); i++)
		for (int j = 0; j < m; j++)
			arr.push_back(tmp[i]);

	dfs(0);

	return 0;
}