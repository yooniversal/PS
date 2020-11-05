//11286
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 1001
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

struct P {
	int num, mark;
	P(int a, int b) : num(a), mark(b) {}
};

struct cmp {
	bool operator()(const P& a, const P& b) const {
		if(a.num != b.num) return a.num > b.num;
		return a.mark > b.mark;
	}
};

priority_queue<P, vector<P>, cmp> pq;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	while (n--) {
		int x; cin >> x;
		if (x != 0) {
			if (x < 0) pq.push(P(-x, -1));
			else pq.push(P(x, 1));
		}
		else {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top().num * pq.top().mark << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}