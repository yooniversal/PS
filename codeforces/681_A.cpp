#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 300005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

bool GCD(int a, int b) {
	while (b) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	if (a != 1) return true;
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi a;
		for (int start = 2; start <= 4 * n; start++) {
			bool fin = false;
			a.push_back(start);
			for (int i = start + 1; i <= 4 * n; i++) {
				bool flag = true;
				for (int j = 0; j < a.size(); ++j) {
					if (i % a[j] == 0 || !GCD(a[j], i)) {
						flag = false;
						break;
					}
				}
				if (flag) {
					a.push_back(i);
				}
				if (a.size() == n) {
					fin = true;
					break;
				}
			}
			if (fin) {
				for (int aa : a) cout << aa << ' ';
				cout << '\n';
				break;
			}
			a.clear();
		}
	}

	return 0;
}