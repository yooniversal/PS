//17219
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 4005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	map<string, string> pw;
	while (n--) {
		string id, PW; cin >> id >> PW;
		pw[id] = PW;
	}
	while (m--) {
		string v; cin >> v;
		cout << pw[v] << '\n';
	}

	return 0;
}