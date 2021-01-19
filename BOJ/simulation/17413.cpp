//17413
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	string tmp = "";
	int start = -1; //태그가 시작되면 시작된 위치를 기록, 기본값은 -1
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '<') {
			start = i;
			if (!tmp.empty()) {
				reverse(tmp.begin(), tmp.end());
				cout << tmp;
				tmp = "";
			}
			continue;
		}
		if (s[i] == '>') {
			cout << s.substr(start, i-start+1);
			start = -1;
			continue;
		}

		if (start == -1) {
			if (s[i] != ' ') {
				tmp += s[i];
				if (i == s.size() - 1) {
					reverse(tmp.begin(), tmp.end());
					cout << tmp << ' ';
				}
			}
			else {
				reverse(tmp.begin(), tmp.end());
				cout << tmp << ' ';
				tmp = "";
			}
		}
	}
	cout << '\n';

	return 0;
}