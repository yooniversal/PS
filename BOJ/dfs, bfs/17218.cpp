//17218
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

vi node[100001];
bool chk[100001];
int p[100001];

void DFS(int parent, int root) {
	p[root] = parent;

	for (auto& next : node[root]) {
		if (chk[next]) continue;
		chk[next] = true;
		DFS(root, next);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	chk[1] = true;
	DFS(-1, 1);

	for (int i = 2; i <= n; ++i)
		cout << p[i] << '\n';

	return 0;
}