//16470
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 605
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	double all = 0;
	map<string, int> cnt;
	set<string> list;
	string s;
	while (getline(cin, s)) {
		++cnt[s]; all += 1.0;
		list.insert(s);
	}

	double ret = 0;
	for (auto it = list.begin(); it != list.end(); ++it) {
		ret += (cnt[*it] / all) * (cnt[*it] / all);
	}
	ret = 1 - ret;
	printf("%lf", ret);

	return 0;
}