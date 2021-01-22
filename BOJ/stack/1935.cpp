//1935
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

double a[27];
stack<double> st;
double cur = 987654321.0; //기본값

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < s.size(); ++i) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			if (cur != 987654321.0) {
				st.push(cur);
				cur = 987654321.0;
			}
			st.push(a[s[i] - 'A']);
		}
		else {
			//cur 초기화
			if (cur == 987654321.0) {
				cur = st.top(); st.pop();
			}

			if (s[i] == '+') {
				cur = st.top() + cur; st.pop();
			}
			else if (s[i] == '-') {
				cur = st.top() - cur; st.pop();
			}
			else if (s[i] == '*') {
				cur = st.top() * cur; st.pop();
			}
			else {
				cur = st.top() / cur; st.pop();
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << cur << '\n';

	return 0;
}