//14697
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[305];
int a, b, c, n;
vi v;

int f(int cur) {
	if (cur == 0) return 1;
	if (cur < 0) return 0;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 3; ++i)
		ret = max(ret, f(cur - v[i]));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> a >> b >> c >> n;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	cout << f(n);

	return 0;
}