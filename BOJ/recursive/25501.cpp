// 25501
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int recursion(string &s, int l, int r, int &cnt)
{
	++cnt;
	if (l >= r)
		return 1;
	else if (s[l] != s[r])
		return 0;
	else
		return recursion(s, l + 1, r - 1, cnt);
}

ii isPalindrome(string &s)
{
	int cnt = 0;
	int ret = recursion(s, 0, s.size() - 1, cnt);
	return {ret, cnt};
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		string s;
		cin >> s;

		auto ret = isPalindrome(s);
		printf("%d %d\n", ret.first, ret.second);
	}

	return 0;
}