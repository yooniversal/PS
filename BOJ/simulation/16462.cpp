//16462
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

	int n; cin >> n;
	double ret = 0;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		if (s.size() >= 3) ret += 100;
		else {
			for (int j = 0; j < s.size(); ++j)
				if (s[j] == '0' || s[j] == '6')
					s[j] = '9';
			ret += stoi(s);
		}
	}
	double tmp = ret / n - floor(ret/n);
	int add = tmp >= 0.5 ? 1 : 0;
	cout << floor(ret / n) + add << '\n';

	return 0;
}