//3372
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1001, INF = 1000000001, MOD = 1234567;

ll board[101][101];
string cache[101][101];
int n;

string add(const string& input1, const string& input2) {
	int ml = input1.size(), nl = input2.size();;
	vi m(105, 0), n(105, 0), s(105, 0);

	for (int i = 0; i < ml; i++)
		m[ml - i - 1] = input1[i] - '0';

	for (int i = 0; i < nl; i++)
		n[nl - i - 1] = input2[i] - '0';

	int maxx = max(ml, nl);

	int carry = 0;
	for (int i = 0; i < maxx; i++) {
		int tmp = m[i] + n[i] + carry;
		carry = tmp / 10;
		s[i] = tmp % 10;
	}

	if (carry > 0) {
		s[maxx] = carry;
		maxx++;
	}

	string ret;
	for (int i = 0; i < maxx; i++)
		ret += s[maxx - i - 1] + '0';
	return ret;
}

bool OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return true;
	return false;
}

string f(int x, int y) {
	if (x == n - 1 && y == n - 1) return "1";
	if (OOB(x, y)) return "0";
	if (board[x][y] == 0) return "0";
	string& ret = cache[x][y];
	if (ret != "-1") return ret;
	ret = add(f(x + board[x][y], y), f(x, y + board[x][y]));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 101; ++i) for (int j = 0; j < 101; ++j) {
		cache[i][j] = "-1";
	}

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	cout << f(0, 0) << '\n';

	return 0;
}