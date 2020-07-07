//11098

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, n;
	long long money, richm;
	string name, rich;

	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> money >> name;
			if (i == 0) {
				richm = money;
				rich = name;
			}
			else {
				if (richm < money) {
					richm = money;
					rich = name;
				}
			}
		}

		cout << rich << "\n";
	}

	return 0;
}