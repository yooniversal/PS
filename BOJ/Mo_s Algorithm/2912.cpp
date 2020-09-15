//2912

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
#define MAX 300001
#define MAXV 10001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int sqrtN;
int A[MAX];
int cnt[MAXV];
int ret[MAX];

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

	int n, c; cin >> n >> c;
	sqrtN = sqrt(n);
	for (int i = 0; i < n; i++) cin >> A[i];

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		Q[i] = QueryNode(l - 1, r - 1, i);
	}
	sort(Q, Q + m);

	int cur = 0;
	int s = Q[0].s, e = Q[0].e;
	for (int i = s; i <= e; i++)
		++cnt[A[i]];
	for (int i = 1; i <= c; i++)
		if (cnt[cur] < cnt[i]) cur = i;
	if (cnt[cur] <= (e - s + 1) / 2) cur = 0;
	ret[Q[0].n] = cur;

	for (int i = 1; i < m; i++) {
		while (Q[i].s < s) ++cnt[A[--s]];
		while (e < Q[i].e) ++cnt[A[++e]];
		while (Q[i].s > s) --cnt[A[s++]];
		while (e > Q[i].e) --cnt[A[e--]];
		for (int i = 1; i <= c; i++)
			if (cnt[cur] < cnt[i]) cur = i;
		if (cnt[cur] <= (e - s + 1) / 2) cur = 0;
		ret[Q[i].n] = cur;
	}

	for (int i = 0; i < m; i++)
		if (!ret[i]) cout << "no\n";
		else cout << "yes " << ret[i] << '\n';

	return 0;
}