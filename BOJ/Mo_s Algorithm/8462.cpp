//8462

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MAXV 1000001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int sqrtN;
int A[MAX];
ll cnt[MAXV];
ll ret[MAX];

struct QueryNode {
	int s, e, n;
	QueryNode() : QueryNode(0, 0, -1) {}
	QueryNode(int s1, int e1, int n1) : s(s1), e(e1), n(n1) {}
	bool operator<(const QueryNode& O) const {
		if (s / sqrtN != O.s / sqrtN) return (s / sqrtN < O.s / sqrtN);
		return (e < O.e);
	}
};

QueryNode Q[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	sqrtN = sqrt(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		Q[i] = QueryNode(l - 1, r - 1, i);
	}
	sort(Q, Q + m);

	ll cur = 0;
	int s = Q[0].s, e = Q[0].e;
	for (int i = s; i <= e; i++) {
		ll prev_cnt = cnt[A[i]]++;
		cur += (prev_cnt * 2 + 1) * A[i];
	}
	ret[Q[0].n] = cur;

	for (int i = 1; i < m; i++) {
		while (Q[i].s < s) {
			ll prev_cnt = cnt[A[--s]]++;
			cur += (prev_cnt * 2 + 1) * A[s];
		}
		while (e < Q[i].e) {
			ll prev_cnt = cnt[A[++e]]++;
			cur += (prev_cnt * 2 + 1) * A[e];
		}
		while (Q[i].s > s) {
			ll prev_cnt = cnt[A[s]]--;
			cur += (prev_cnt * (-2) + 1) * A[s++];
		}
		while (e > Q[i].e) {
			ll prev_cnt = cnt[A[e]]--;
			cur += (prev_cnt * (-2) + 1) * A[e--];
		}
		ret[Q[i].n] = cur;
	}

	for (int i = 0; i < m; i++)
		cout << ret[i] << '\n';

	return 0;
}