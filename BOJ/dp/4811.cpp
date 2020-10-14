//13398
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

ll cache[61][31][31];
int n;

ll f(int day, int whole, int half) {
	if (day == 2 * n) return 1;
	ll& ret = cache[day][whole][half];
	if (ret != -1) return ret;
	ret = 0;
	if(whole < n) ret += f(day + 1, whole+1, half);
	if(whole > half) ret += f(day + 1, whole, half+1);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		if (n == 0) break;
		cout << f(0, 0, 0) << '\n';
	}

	return 0;
}