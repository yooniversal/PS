//2629
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

//중간 값이 음수가 될 수 있음에 주의
int cache[70001][31][2];
int n, l, r;
vi c;

int f(int num, int a, int b) {
	if (num < 0) return 0;
	if (a == n) return 0;
	int& ret = cache[num][a][b];
	if (ret != -1) return ret;
	ret = 0;
	ret += f(num + c[a], a + 1, 0);
	ret += f(num - c[a], a + 1, 1);
	ret += f(num, a + 1, 0);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));

	cin >> n;
	c.resize(n);
	for (int i = 0; i < n; ++i) cin >> c[i];
	int m; cin >> m;
	while (m--) {
		int num; cin >> num;
		if (f(num, 0, 0)) cout << "Y ";
		else cout << "N ";
	}

	return 0;
}