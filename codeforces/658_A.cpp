#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		sort(a.begin(), a.end()); sort(b.begin(), b.end());

		bool key = false;
		if (n < m) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (a[i] == b[j]) {
						cout << "YES" << '\n';
						cout << 1 << " " << a[i] << '\n';
						i = n; j = m;
						key = true;
					}
				}
			}
		}
		else {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (b[i] == a[j]) {
						cout << "YES" << '\n';
						cout << 1 << " " << a[j] << '\n';
						i = m; j = n;
						key = true;
					}
				}
			}
		}

		if (!key) cout << "NO" << '\n';
	}

	return 0;
}