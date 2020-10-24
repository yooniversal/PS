//1793
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

string cache[251];

string add(const string& input1, const string& input2) {
	int ml = input1.size(), nl = input2.size();;
	vi m(1001, 0), n(1001, 0), s(1001, 0);

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

string f(int n) {
	if (n <= 1) return "1";
	string& ret = cache[n];
	if (ret != "-1") return ret;
	ret = "0";
	ret = add(f(n - 1), f(n - 2));
	ret = add(ret, f(n-2));
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int n;
	while (scanf("%d", &n)>0) {
		for (int i = 0; i < 251; ++i) cache[i] = "-1";
		cout << f(n) << '\n';
	}

	return 0;
}