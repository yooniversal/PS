//11655
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

char f(char a) {
	if ('a' <= a && a <= 'z') {
		if (a + 13 > 'z') return a + 12 - 'z' + 'a';
		return a + 13;
	}
	else {
		if (a + 13 > 'Z') return a + 12 - 'Z' + 'A';
		return a + 13;
 	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); ++i) {
		if (isalpha(s[i]) == 0) cout << s[i];
		else cout << f(s[i]);
	}
	cout << '\n';

	return 0;
}