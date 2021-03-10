//10825
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

struct P {
	string name;
	int a, b, c;

	bool operator<(const P& p) {
		if (a != p.a) return a > p.a;
		if (b != p.b) return b < p.b;
		if(c != p.c) return c > p.c;
		return name < p.name;
	}
};

int n;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	vector<P> p;
	for (int i = 0; i < n; ++i) {
		string name; cin >> name;
		int a, b, c; cin >> a >> b >> c;
		p.push_back({ name,a,b,c });
	}
	sort(p.begin(), p.end());

	for (auto& cur : p) {
		cout << cur.name << '\n';
	}

	return 0;
}