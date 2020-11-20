//16460
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

bool find(string& a, string& b) {
	for (int i = 0; i < a.size(); ++i)
		if (a[i] == b[0]) return true;
	return false;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string NAME, s; int dist;
	cin >> NAME >> s >> dist;
	int n; cin >> n;
	vector<string> ret;
	while (n--) {
		string name, sex; int d;
		cin >> name >> sex >> d;
		if (find(s, sex) && dist >= d) 
			ret.push_back(name);
	}
	sort(ret.begin(), ret.end());
	if (ret.size())
		for (auto& s : ret) cout << s << '\n';
	else cout << "No one yet\n";

	return 0;
}