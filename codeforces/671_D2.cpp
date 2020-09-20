#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 100001
typedef long long ll;

int a[MAX];
int ret[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int m = n / 2;
	vector<int> s, b;
	for (int i = 0; i < n; ++i) {
		if (i < m) s.push_back(a[i]);
		else b.push_back(a[i]);
	}

	int sp = 0, bp = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) ret[i] = b[bp++];
		else ret[i] = s[sp++];
	}

	int cnt = 0;
	for (int i = 1; i < n - 1; ++i)
		if (ret[i - 1] > ret[i] && ret[i] < ret[i + 1]) ++cnt;
	cout << cnt << '\n';

	for (int i = 0; i < n; ++i) cout << ret[i] << " ";
	cout << '\n';

	return 0;
}