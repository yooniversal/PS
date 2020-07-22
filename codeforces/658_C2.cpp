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
		vector<int> ans1, ans2;
		cin >> n >> a >> b;
		a += '0'; b += '0';
		for (int i = 1; i <= n; i++) {
			if (a[i - 1] != a[i]) ans1.push_back(i);
			if (b[i - 1] != b[i]) ans2.push_back(i);
		}	
		ans1.insert(ans1.end(), ans2.rbegin(), ans2.rend());
		cout << ans1.size() << " ";
		for (int i = 0; i < ans1.size(); i++)
			cout << ans1[i] << " ";
		cout << '\n';
	}

	return 0;
}