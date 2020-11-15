//9184
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 4005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[120][120][120];

int f(int a, int b, int c) {
	if (a <= 50 || b <= 50 || c <= 50) return 1;
	int& ret = cache[a][b][c];
	if (ret != -1) return ret;
	//printf("a:%d b:%d c:%d\n", a, b, c);
	ret = 0;
	if (a > 70 || b > 70 || c > 70) ret = f(70, 70, 70);
	else if (a < b && b < c) ret = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
	else ret = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	while (1) {
		int a, b, c; cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, f(a+50, b+50, c+50));
	}

	return 0;
}