//16500
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 10001
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

string s;
int n;
int cache[101];
vector<string> word;

int f(int cur) {
	if (cur == s.size()) return 1;
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < n; ++i) {
		if (s.size() - cur < word[i].size()) continue;
		bool pass = true;
		for (int j = 0; j < word[i].size(); ++j) {
			if (s[cur + j] != word[i][j]) {
				pass = false;
				break;
			}
		}
		if (pass) ret = max(ret, f(cur + word[i].size()));
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> s >> n;
	word.resize(n);
	for (int i = 0; i < n; ++i) cin >> word[i];
	cout << f(0);

	return 0;
}