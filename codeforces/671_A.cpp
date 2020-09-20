#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 100001
typedef long long ll;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;

		int R[2] = { 0 }, B[2] = { 0 }; //odd, even
		for (int i = 0; i < s.size(); ++i) {
			if ((i + 1) % 2) {
				if ((s[i] - '0') % 2) ++R[0];
				else ++R[1];
			}
			else {
				if ((s[i] - '0') % 2) ++B[0];
				else ++B[1];
			}
		}

		if (n % 2 == 0) {
			if (B[1]) cout << 2 << '\n';
			else cout << 1 << '\n';
		}
		else {
			if (R[0]) cout << 1 << '\n';
			else cout << 2 << '\n';
		}
	}

	return 0;
}