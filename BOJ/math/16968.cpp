//16968
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int ret = 1;
	for (int i = 0; i < s.size(); ++i) {
		if (i) {
			if (s[i] == 'c') {
				if (s[i - 1] == 'c') ret *= 25;
				else ret *= 26;
			}
			else if (s[i] == 'd') {
				if (s[i - 1] == 'd') ret *= 9;
				else ret *= 10;
			} 
		}
		else {
			if (s[i] == 'c') ret *= 26;
			else ret *= 10;
		}
	}
	cout << ret << '\n';

	return 0;
}