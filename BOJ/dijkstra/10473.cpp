//10473
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

struct P {
	double x, y;
};

struct cmp {
	bool operator()(pair<double, int>& a, pair<double, int>& b) {
		return a.first > b.first;
	}
};

P s, e, cannon[101];

double dist(P& a, P& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n;
double d[MAX];
bool chk[MAX];
priority_queue<pair<double, int>, vector<pair<double, int>>, cmp> pq;

void dijkstra() {
	while (!pq.empty()) {
		int cur = pq.top().second;
		double distance = pq.top().first;
		pq.pop();

		if (chk[cur]) continue;
		chk[cur] = true;

		if (d[cur] < distance) continue;
		for (int next = 1; next <= n; ++next) {
			if (cur == next) continue;
			double nextDist = distance + min(abs(50.0 - dist(cannon[cur], cannon[next]))/5.0 + 2.0, dist(cannon[cur], cannon[next])/5.0);
			if (d[next] > nextDist) {
				d[next] = nextDist;
				pq.push({ nextDist, next });
			}
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s.x >> s.y >> e.x >> e.y >> n;
	double ret = dist(s, e) / 5.0;
	for (int i = 1; i <= n; ++i) {
		cin >> cannon[i].x >> cannon[i].y;
		d[i] = dist(s, cannon[i]) / 5.0; //start -> 대포
		pq.push({ d[i], i });
	}

	dijkstra();

	//대포 -> end
	for (int i = 1; i <= n; ++i) {
		ret = min(ret, d[i] + min(abs(50.0 - dist(cannon[i], e)) / 5.0 + 2.0, dist(cannon[i], e) / 5.0));
	}
	cout << ret;

	return 0;
}