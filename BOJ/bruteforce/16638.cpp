//16638
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100001, INF = 1000000001, MOD = 1000000007;

int n;
string s;
bool sel[20], mul[20];

ii priority(int i, int init) {
	int ret = init;
	if (sel[i + 2]) {
		if (s[i + 3] == '+') ret *= (s[i + 2] - '0') + (s[i + 4] - '0');
		else if (s[i + 3] == '-') ret *= (s[i + 2] - '0') - (s[i + 4] - '0');
		else ret *= (s[i + 2] - '0') * (s[i + 4] - '0');

		if (mul[i + 4]) {
			ii next = priority(i + 4, 1);
			return { ret * next.first, 4 + next.second };
		}
		else return { ret, 5 };
	}
	else if (mul[i + 2]) {
		ii next = priority(i + 2, s[i+2]-'0');
		return { ret * next.first, 2 + next.second };
	}
	return { ret * (s[i + 2] - '0'), 3 };
}

int cal() {
	int ret = 0, tmp = 0;
	char oper = '+';
	for (int i = 0; i < n; ) {
		//숫자
		if (i % 2 == 0) {
			//괄호
			if (sel[i]) {
				if (mul[i + 2]) {
					if (s[i + 1] == '+') tmp = (s[i] - '0') + (s[i + 2] - '0');
					else if (s[i + 1] == '-') tmp = (s[i] - '0') - (s[i + 2] - '0');
					else tmp = (s[i] - '0') * (s[i + 2] - '0');

					ii cur = priority(i+2, 1);
					tmp *= cur.first;

					i += cur.second + 2;
				}
				else {
					if (s[i + 1] == '+') tmp = (s[i] - '0') + (s[i + 2] - '0');
					else if (s[i + 1] == '-') tmp = (s[i] - '0') - (s[i + 2] - '0');
					else tmp = (s[i] - '0') * (s[i + 2] - '0');
					i += 3;
				}
			}
			//곱
			else if (mul[i]) {
				ii cur = priority(i, s[i]-'0');
				tmp = cur.first;
				i += cur.second;
			}
			else {
				tmp = s[i] - '0';
				++i;
			}

			//답 갱신
			if (oper == '+') ret += tmp;
			else if (oper == '-') ret -= tmp;
			else ret *= tmp;
		}
		//연산자
		else {
			oper = s[i];
			++i;
		}
	}
	return ret;
}

int DFS(int prev, int cur, int all) {
	if (cur == all) return cal();
	int ret = INT_MIN;

	for (int i = prev + 2; i < (n - 1) / 2; ++i) {
		sel[i * 2] = true;
		ret = max(ret, DFS(i, cur + 1, all));
		sel[i * 2] = false;
	}

	return ret;
}

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*')
			mul[i - 1] = true;
	}

	if (n >= 5) {
		int ret = INT_MIN;
		for (int st = 0; st < (n - 1) / 2; ++st) {
			sel[st * 2] = true;
			for (int all = 1; all <= (n - 1) / 2; ++all) {
				ret = max(ret, DFS(st, 1, all));
			}

			sel[st * 2] = false;
		}
		cout << ret << '\n';
	}
	else
		cout << cal() << '\n';
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}