//14431
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 9001, INF = 1000000001, MOD = 1000000007;

int dist[4005];
bool chk[4005], prime[MAX];
vii a[4005];
ii xy[4005];

void eratosthenes() {
    memset(prime, true, sizeof(prime));
    int SN = sqrt(MAX);
    for (int i = 2; i <= SN; i++) {
        if (!prime[i]) continue;
        for (int j = i + i; j < MAX; j += i)
            prime[j] = false;
    }
    prime[0] = prime[1] = false;
}

void dijkstra(int start) {
	for (int i = 0; i < 4005; ++i) dist[i] = INF;
	dist[start] = 0;
	priority_queue<ii> pq; //가까운 순서대로 처리하기 위함
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (chk[cur]) continue;
		chk[cur] = true;

		//최단거리가 아님
		if (dist[cur] < distance) continue;
		for (auto& next : a[cur]) {
			int nextDist = distance + next.second;
			if (nextDist < dist[next.first]) {
				dist[next.first] = nextDist;
				pq.push({ -nextDist, next.first });
			}
		}
	}
}

int DIST(ii& a, ii& b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    eratosthenes();
	cin >> xy[1].first >> xy[1].second >> xy[2].first >> xy[2].second;
	if (prime[DIST(xy[1], xy[2])]) {
		a[1].push_back({ 2, DIST(xy[1], xy[2]) });
		a[2].push_back({ 1, DIST(xy[1], xy[2]) });
	}

	int n; cin >> n;
	for (int i = 3; i <= n + 2; ++i) {
		cin >> xy[i].first >> xy[i].second;
	}

	for (int i = 1; i <= n + 2; ++i) {
		for (int j = 2; j <= n + 2; ++j) {
			if (prime[DIST(xy[i], xy[j])]) {
				a[i].push_back({ j, DIST(xy[i], xy[j]) });
				a[j].push_back({ i, DIST(xy[i], xy[j]) });
			}
		}
	}

	dijkstra(1);

	if (dist[2] == INF) cout << -1 << '\n';
	else cout << dist[2] << '\n';

	return 0;
}