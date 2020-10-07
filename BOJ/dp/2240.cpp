//2240
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MAX 4000005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int cache[1005][35][3];
int t, w;
vi plum;

int f(int time, int chance, int place) {
	if (time == t) return 0;
	int& ret = cache[time][chance][place];
	if (ret != -1) return ret;
	ret = 0;
	int diff;
	if (place == 1) diff = 2;
	else diff = 1;
	int stop = place == plum[time];
	int move = diff == plum[time];
	ret = max(ret, f(time + 1, chance, place)+stop);
	if (chance) ret = max(ret, f(time + 1, chance - 1, diff)+move);
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(cache, -1, sizeof(cache));
	cin >> t >> w;
	plum.resize(t);
	for (int i = 0; i < t; ++i) cin >> plum[i];
	cout << f(0, w, 1);

	return 0;
}