//18111
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 257
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct F {
	int floor, p, m, t;
	F(): F(-1, -INF, -INF) {}
	F(int a, int b, int c) : floor(a), p(b), m(c), t(0) {}
};

int block[MAX];
F floors[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, b; cin >> n >> m >> b;
	int lf = INF, hf = -1;
	for (int i = 0; i < n * m; ++i) {
		int a; cin >> a;
		block[a]++;
		lf = min(lf, a);
		hf = max(hf, a);
	}

	for (int i = lf; i <= hf; ++i) {
		int p = 0, m = 0;
		for (int j = 0; j < MAX; ++j) {
			if (j < i) p += block[j] * (i - j);
			if (j > i) m += block[j] * (j - i);
		}
		floors[i] = F(i, p, m);
	}
	
	for (int i = lf; i <= hf; ++i) {
		int t = 0;
		if (b > 0) {
			t += min(b, floors[i].p);
			floors[i].p -= min(b, floors[i].p);
		}

		if (floors[i].m > 0) {
			t += floors[i].m * 2;
			if (floors[i].p > 0) {
				t += min(floors[i].m, floors[i].p);
				floors[i].p -= min(floors[i].m, floors[i].p);
			}
		}

		floors[i].t = t;
	}

	int T = INF, floor = -1;
	for (int i = lf; i <= hf; ++i) {
		if (floors[i].p != 0) continue;
		if (T > floors[i].t) {
			T = floors[i].t;
			floor = floors[i].floor;
		}
		else if (T == floors[i].t) {
			floor = max(floor, floors[i].floor);
		}
	}

	cout << T << " " << floor;



	return 0;
}