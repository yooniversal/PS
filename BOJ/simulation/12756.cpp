//12756
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 10000001, INF = 1000000001, MOD = 1234567;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int aa, al, ba, bl; cin >> aa >> al >> ba >> bl;
	while (al > 0 && bl > 0) {
		al -= ba;
		bl -= aa;
	}
	if (al <= 0 && bl <= 0) cout << "DRAW\n";
	else if (bl <= 0) cout << "PLAYER A\n";
	else if (al <= 0) cout << "PLAYER B\n";

	return 0;
}