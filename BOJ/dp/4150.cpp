//10826
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

string cache[5005];
int n;

string add(const string& input1, const string& input2) {
	int ml = input1.size(), nl = input2.size();;
	vi m(1050, 0), n(1050, 0), s(1050, 0);

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

string f(int cur) {
	if (cur == 0) return "0";
	if (cur == 1) return "1";
	string& ret = cache[cur];
	if (ret != "-1") return ret;
	ret = add(f(cur - 1), f(cur - 2));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 5005; ++i) cache[i] = "-1";
	cin >> n;
	cout << f(n) << '\n';

	return 0;
}