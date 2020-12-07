//16637
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
bool sel[20];

int cal() {
	int ret = 0, tmp = 0;
	char oper = '+';
	for (int i = 0; i < n; ) {
		//숫자
		if (i % 2 == 0) {
			//괄호
			if (sel[i]) {
				if (s[i + 1] == '+') tmp = (s[i] - '0') + (s[i + 2] - '0');
				else if(s[i + 1] == '-') tmp = (s[i] - '0') - (s[i + 2] - '0');
				else tmp = (s[i] - '0') * (s[i + 2] - '0');
				i += 3;
			}
			//괄호X
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

	for (int i = prev+2; i < (n - 1) / 2; ++i) {
		sel[i * 2] = true;
		ret = max(ret, DFS(i, cur + 1, all));
		sel[i * 2] = false;
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> s;
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


	return 0;
}