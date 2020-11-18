//2494
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 10001
#define MOD 10007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int n;
int cache[10001][11];
int A[10001], B[10001];
string a, b;

int f(int cur, int rotate) {
	if (cur == n) return 0;
	int& ret = cache[cur][rotate];
	if (ret != -1) return ret;
	ret = INF;
	int now = (A[cur] + rotate) % 10, next = B[cur];
	for (int i = 0; i < 10; ++i) {
		if ((now + i) % 10 == next) {
			ret = min(ret, f(cur + 1, (rotate + i) % 10) + i);
			ret = min(ret, f(cur + 1, rotate) + 10 - i);
			break;
		}
	}
	return ret;
}

void solve(int cur, int rotate) {
	if (cur == n) return;
	int now = (A[cur] + rotate) % 10, next = B[cur];
	for (int i = 0; i < 10; ++i) {
		if ((now + i) % 10 == next) {
			int L = f(cur + 1, (rotate + i) % 10) + i, R = f(cur + 1, rotate) + 10 - i;
			if (L <= R) {
				printf("%d %d\n", cur + 1, i);
				solve(cur + 1, (rotate + i) % 10);
			}
			else {
				printf("%d %d\n", cur + 1, i - 10);
				solve(cur + 1, rotate);
			}
			return;
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		A[i] = a[i] - '0';
		B[i] = b[i] - '0';
	}
	cout << f(0, 0) << '\n';
	solve(0, 0);

	return 0;
}