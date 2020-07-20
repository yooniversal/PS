#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool chk[51];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ans;
		for (int i = 0; i < 2 * n; i++) {
			int tmp;
			cin >> tmp;
			if (!chk[tmp]) {
				ans.push_back(tmp);
				chk[tmp] = true;
			}
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';

		memset(chk, false, sizeof(chk));
	}

	return 0;
}