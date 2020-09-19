#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 100001
typedef long long ll;

bool LOCK[MAX];
int a[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> LOCK[i];

		vector<int> unlock;
		for (int i = 0; i < n; ++i)
			if (!LOCK[i]) unlock.push_back(a[i]);
		sort(unlock.rbegin(), unlock.rend());

		int ptr = 0;
		for (int i = 0; i < n; ++i)
			if (LOCK[i]) cout << a[i] << " ";
			else cout << unlock[ptr++] << " ";
		cout << '\n';
	}

	return 0;
}