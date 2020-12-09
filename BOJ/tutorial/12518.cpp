//12518
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		if (s.back() == 'y' || s.back() == 'Y') cout << "Case #" << i << ": " << s << " is ruled by nobody.\n";
		else if(s.back() == 'a' || s.back() == 'e' || s.back() == 'i' || s.back() == 'o' || s.back() == 'u'
			|| s.back() == 'A' || s.back() == 'E' || s.back() == 'I' || s.back() == 'O' || s.back() == 'U')
			cout << "Case #" << i << ": " << s << " is ruled by a queen.\n";
		else
			cout << "Case #" << i << ": " << s << " is ruled by a king.\n";
	}

	return 0;
}