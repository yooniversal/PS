//1671

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
#define MAX 51
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct shark {
	int a, b, c;

	bool operator<(const shark& s) const {
		if (a == s.a && b == s.b) return c > s.c;
		if (a == s.a) return b > s.b;
		else return a > s.a;
	}
};

vi sharks[MAX];
bool chk[MAX];
int from[MAX];

bool dfs(int cur) {
	for (auto& next : sharks[cur]) {
		if (chk[next]) continue;
		chk[next] = true;

		if (from[next] == -1 || dfs(from[next])) {
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

	fill(from, from + MAX, -1);

	//input
	int n; cin >> n;
	vector<shark> arr(n);
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[i] = { a, b, c };
	}
	sort(arr.begin(), arr.end()); //내림차순 정렬

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			//문제 조건 && j는 i를 먹을 수 없음
			if (arr[i].a >= arr[j].a && arr[i].b >= arr[j].b && arr[i].c >= arr[j].c)
				sharks[i].push_back(j);
		}
	}

	vi ret;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		fill(chk, chk + MAX, false);
		if (dfs(i)) cnt++;
		if (dfs(i)) cnt++;
	}

	cout << n - cnt;

	return 0;
}