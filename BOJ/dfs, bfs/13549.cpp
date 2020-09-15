//13549

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
#define MAX 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int a[MAX];
bool chk[MAX];
int n, k;

void bfs(int cur){
	queue<int> q;
	q.push(cur);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == k) break;
		if (2 * cur <= MAX - 1 && !chk[2*cur]) {
			q.push(2 * cur);
			a[2 * cur] = a[cur];
			chk[2*cur] = true;
		}
		if (cur - 1 >= 0 && !chk[cur-1]) {
			q.push(cur - 1);
			a[cur - 1] = a[cur] + 1;
			chk[cur-1] = true;
		}
		if (cur + 1 <= MAX-1 && !chk[cur+1]) {
			q.push(cur + 1);
			a[cur + 1] = a[cur] + 1;
			chk[cur+1] = true;
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	memset(a, -1, sizeof(a));
	cin >> n >> k;
	a[n] = 0;
	bfs(n);
	cout << a[k] << '\n';

	return 0;
}