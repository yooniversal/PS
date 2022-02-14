//1038
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n;

void scale_up(string& s) {

	int cur = s.size() - 1;
	
	bool flag = false;
	do {

		if (s[cur] == '9') {
			
			int n_size = s.size();
			s = "";
			for (; n_size >= 0; --n_size)
				s += n_size + '0';

			break;
		}

		flag = false;

		s[cur]++;
		
		if (cur - 1 >= 0 && s[cur - 1] <= s[cur]) {

			if (cur == s.size() - 1) {
				s[cur--] = '0';
			}
			else {
				s[cur] = s[cur + 1] + 1;
				cur--;
			}
			flag = true;
		}

	} while (flag);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	string s = "0";
	for (int i = 0; i < n; ++i) {

		if (s == "9876543210") {

			cout << -1 << '\n';
			return 0;
		}

		scale_up(s);
	}

	cout << s << '\n';

	return 0;
}