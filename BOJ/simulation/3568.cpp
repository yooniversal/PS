//3568
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string var; cin >> var;
	while (1) {
		string s; cin >> s;
		string ret = var, name;
		for (int i = s.size() - 2; i >= 0; --i) {
			if (!isalpha(s[i])) {
				if (s[i] == ']') continue;
				if (s[i] == '[') ret += "[]";
				else ret += s[i];
			}
			else
				name += s[i];
		}
		reverse(name.begin(), name.end());
		ret += ' ';
		ret += name;
		ret += ';';
		cout << ret << '\n';
		if (s[s.size() - 1] == ';') break;
	}

	return 0;
}