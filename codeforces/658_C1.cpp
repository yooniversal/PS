#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string a, b;
		vector<int> ans;
		cin >> n >> a >> b;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				if (i > 0) ans.push_back(i + 1);
				ans.push_back(1);
				if (i > 0) ans.push_back(i + 1);
			}
		}

		cout << ans.size() << " ";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}

	return 0;
}