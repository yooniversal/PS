//5698
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

	while (1) {
		string s;
		getline(cin, s);
		if (s == "*") break;
		
		bool flag = true;
		char c = s[0];
		if (isupper(c)) c = c - 'A' + 'a';
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == ' ') {
				char next = s[i + 1];
				if (isupper(next)) next = next - 'A' + 'a';
				if (c != next) {
					flag = false;
					break;
				}
			}
		}
		if (flag) cout << "Y\n";
		else cout << "N\n";
	}

	return 0;
}